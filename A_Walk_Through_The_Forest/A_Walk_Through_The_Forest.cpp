#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int N,M;
vector<vector<pair<int,int>>> record;
vector<int> shortest,cnt;

void DFS(int n){
	int tmp=0;
	for(int i=0 ; i<record[n].size() ; ++i){
		int adj_node=record[n][i].second;
		if(adj_node == 2){
			++tmp;
		}
		else if(shortest[adj_node] < shortest[n]){
			if(cnt[adj_node]){
				tmp+=cnt[adj_node];			
			}
			else{
				DFS(adj_node);
				tmp+=cnt[adj_node];
			}
		}		
	}
	cnt[n]=tmp;
}


int main(){
	while(cin >> N >> M){
		if(!N) break;
		record.clear();
		record.resize(N+1);
		for(int i=0 ; i<M ; ++i){
			int a,b,c;
			cin >> a >> b >> c;
			record[a].push_back(make_pair(c,b));
			record[b].push_back(make_pair(c,a));
		}
		
		shortest.clear();
		shortest.resize(N+1,INF);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
		pq.push(make_pair(0,2));
		vector<bool> flag(N+1);
		while(!pq.empty()){
			int choose=pq.top().second;
			if(flag[choose]){
				pq.pop();
				continue;
			}
			flag[choose]=1;
			shortest[choose]=pq.top().first;
			//cout << choose << "  " << shortest[choose] << endl;
			pq.pop();
			for(int j=0 ; j<record[choose].size() ; ++j){
				int adj_len=record[choose][j].first;
				int adj_node=record[choose][j].second;
				if(shortest[choose]+adj_len < shortest[adj_node]){
					shortest[adj_node]=shortest[choose]+adj_len;
					pq.push(make_pair(shortest[adj_node],adj_node));
				}
			}
		}
		
		cnt.clear();
		cnt.resize(N+1);
		DFS(1);
		/*queue<int> BFS;
		BFS.push(1);
		int cnt=0;
		while(!BFS.empty()){
			int choose=BFS.front();
			BFS.pop();
			for(int i=0 ; i<record[choose].size() ; ++i){
				int adj_node=record[choose][i].second;
				if(adj_node == 2) ++cnt;
				else if(shortest[adj_node] < shortest[choose]) BFS.push(adj_node);
			}
		}*/
		cout << cnt[1] << endl;
		//for(int i=1 ; i<N+1 ; ++i) cout << "Node:" << i << "  Cnt:" << cnt[i] << endl;
	}
}
