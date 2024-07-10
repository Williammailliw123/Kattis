#include<bits/stdc++.h>
using namespace std;
//先將原題目轉成bipartite graph，再使用Hopcroft-Karp Algorithm解決

bool swapable(string a,string b){
	int cnt=0;
	for(int i=0 ; i<a.size() ; ++i){
		if(a[i] == b[i]) continue;
		++cnt;
	}
	if(cnt == 2) return 1;
	else return 0;
}

int trace(int y,int mx[],int my[],int px[],int py[])
{
	int x = py[y], yy = px[x];
	py[y] = px[x] = -1;
	if (mx[x] == -1 || (yy != -1 && trace(yy,mx,my,px,py))){
		mx[x] = y; my[y] = x;
		return 1;
	}
	return 0;
}

int bip_match(int start,const vector<vector<int>> adj,vector<bool>& vis,int &vis_cnt){
	vis[start]=1;
	++vis_cnt;
	if(adj[start].empty()) return 1;
	vector<int> conec;
	conec.push_back(start);
	vector<int> XX,YY;
	vector<int> col(adj.size(),-1);
	col[start]=0;
	XX.push_back(start);
	for(int i=0 ; i<conec.size() ; ++i){
		int cur=conec[i];
		int group_num=(col[cur]+1)%2;
		for(int j=0 ; j<adj[cur].size() ; ++j){
			int nei=adj[cur][j];
			if(!vis[nei]){
				++vis_cnt;
				vis[nei]=1;
				conec.push_back(nei);
				col[nei]=group_num;
				if(!group_num) XX.push_back(nei);
				else YY.push_back(nei);
			}
		}
	}
	int X=XX.size(),Y=YY.size();
	int mx[X],my[Y];
	int px[X],py[Y];
	bool tmp_adj[X][Y];
	for(int i=0 ; i<X ; ++i){
		for(int j=0 ; j<Y ; ++j) tmp_adj[i][j]=0;
	}
	map<int,int> rev;
	for(int i=0 ; i<Y ; ++i) rev[YY[i]]=i;
	for(int i=0 ; i<X ; ++i){
		for(int j=0 ; j<adj[XX[i]].size() ; ++j){
			int nei=adj[XX[i]][j];
			int id=rev[nei];
			tmp_adj[i][id]=1;
		}
	}
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));

	int q[X], *qf, *qb;
	int c = 0;
	while (true)
	{
		memset(px, -1, sizeof(px));
		memset(py, -1, sizeof(py));
		qf = qb = q;

		// 把X的未匹配點，作為交錯森林的樹根。
		for (int x=0; x<X; ++x)
			if (mx[x] == -1)
				*qb++ = x;

		bool ap = false;	// 是否存在擴充路徑
		for (int* tqb = qb; qf < tqb && !ap; tqb = qb)
			for (int x=*qf++, y=0; y<Y; ++y)
				if (tmp_adj[x][y] /*&& mx[x] != y*/ && py[y] == -1)
				{
					py[y] = x;
					if (my[y] == -1) ap = true;
					else *qb++ = my[y], px[my[y]] = y;
				}
		if (!ap) break;
		for (int y=0; y<Y; ++y)
			if (my[y] == -1 && py[y] != -1)
				c += trace(y,mx,my,px,py);
	}
	return conec.size()-c;
}

int main(){
	cout.sync_with_stdio(false);
	int N;
	while(cin >> N){
		vector<string> V;
		for(int i=0 ; i<N ; ++i){
			string tmp_s;
			cin >> tmp_s;
			V.push_back(tmp_s);
		}
		vector<vector<int>> adj(N);
		for(int i=0 ; i<N-1 ; ++i){
			for(int j=i+1 ; j<N ; ++j){
				if(swapable(V[i],V[j])){
					adj[i].push_back(j);
					adj[j].push_back(i); 
				}
			}
		}
		vector<bool> vis(N,0);
		int vis_cnt=0;
		int result=0;
		while(vis_cnt != N){
			int cur;
			for(int i=0 ; i<N ; ++i){
				if(!vis[i]){
					cur=i;
					break;
				}
			}
			result+=bip_match(cur,adj,vis,vis_cnt);
		}
		cout << result << endl;
	}
}
