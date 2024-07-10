#include<bits/stdc++.h>
using namespace std;

int R,C;
vector<vector<char>> D;
vector<vector<bool>> vis;
queue<pair<pair<int,int>,int>> record;
bool flag;
int result;

void F(int rr,int cc,int cnt){
	if(flag) return;
	if(rr-1==1 && D[rr-1][cc]=='D' || cc-1==1 && D[rr][cc-1]=='D' ||
		rr+1==R && D[rr+1][cc]=='D' || cc+1==C && D[rr][cc+1]=='D'){
			flag=1;
			result=cnt;
			return;
	}
	if(!vis[rr-1][cc] && D[rr-1][cc]!='#'){
		vis[rr-1][cc]=1;
		if(D[rr-1][cc] == 'D') F(rr-1,cc,cnt);
		else record.push(make_pair(make_pair(rr-1,cc),cnt+1));
	}
	if(!vis[rr+1][cc] && D[rr+1][cc]!='#'){
		vis[rr+1][cc]=1;
		if(D[rr+1][cc] == 'D') F(rr+1,cc,cnt);
		else record.push(make_pair(make_pair(rr+1,cc),cnt+1));
	}
	if(!vis[rr][cc-1] && D[rr][cc-1]!='#'){
		vis[rr][cc-1]=1;
		if(D[rr][cc-1] == 'D') F(rr,cc-1,cnt);
		else record.push(make_pair(make_pair(rr,cc-1),cnt+1));
	}
	if(!vis[rr][cc+1] && D[rr][cc+1]!='#'){
		vis[rr][cc+1]=1;
		if(D[rr][cc+1] == 'D') F(rr,cc+1,cnt);
		else record.push(make_pair(make_pair(rr,cc+1),cnt+1));
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> R >> C){
		vector<char> ch(C+1);
		D.clear();
		D.resize(R+1,ch);
		vector<bool> bo(C+1);
		vis.clear();
		vis.resize(R+1,bo);
		queue<pair<pair<int,int>,int>> emp;
		swap(emp, record);
		flag=0;
		for(int i=1 ; i<R+1 ; ++i){
			for(int j=1 ; j<C+1 ; ++j){
				cin >> D[i][j];
			}
		}
		int r,c;
		cin >> r >> c;		
		record.push(make_pair(make_pair(r,c),1));
		vis[r][c]=1;
		while(!flag){
			int rr=record.front().first.first,cc=record.front().first.second,cnt=record.front().second;
			record.pop();
			if(rr-1==1 && D[rr-1][cc]=='D' || cc-1==1 && D[rr][cc-1]=='D' ||
			rr+1==R && D[rr+1][cc]=='D' || cc+1==C && D[rr][cc+1]=='D'){
				result=cnt;
				break;
			}
			if(!vis[rr-1][cc] && D[rr-1][cc]!='#'){
				vis[rr-1][cc]=1;
				if(D[rr-1][cc] == 'D') F(rr-1,cc,cnt);
				else record.push(make_pair(make_pair(rr-1,cc),cnt+1));
			}
			if(!vis[rr+1][cc] && D[rr+1][cc]!='#'){
				vis[rr+1][cc]=1;
				if(D[rr+1][cc] == 'D') F(rr+1,cc,cnt);
				else record.push(make_pair(make_pair(rr+1,cc),cnt+1));
			}
			if(!vis[rr][cc-1] && D[rr][cc-1]!='#'){
				vis[rr][cc-1]=1;
				if(D[rr][cc-1] == 'D') F(rr,cc-1,cnt);
				else record.push(make_pair(make_pair(rr,cc-1),cnt+1));
			}
			if(!vis[rr][cc+1] && D[rr][cc+1]!='#'){
				vis[rr][cc+1]=1;
				if(D[rr][cc+1] == 'D') F(rr,cc+1,cnt);
				else record.push(make_pair(make_pair(rr,cc+1),cnt+1));
			}
		}
		cout << result << endl;
	}
	return 0;
}
