#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> path;
vector<bool> vis;
int result;

void DFS(int cur,int cnt){
	vis[cur]=1;
	for(int i=0 ; i<path[cur].size() ; ++i){
		if(!path[cur][i]){
			result=max(result,cnt);
			continue;
		}
		if(vis[path[cur][i]]) continue;
		DFS(path[cur][i],cnt+1);
	}
	vis[cur]=0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	while(cin >> n){
		if(!n) break;
		cin >> m;
		path.clear();
		path.resize(n);
		vis.clear();
		vis.resize(n);
		result=1;
		int a,b;
		for(int i=0 ; i<m ; ++i){
			cin >> a >> b;
			path[a].push_back(b);
			path[b].push_back(a);
		}
		DFS(0,1);
		cout << result << endl;
	}
	return 0;
}
