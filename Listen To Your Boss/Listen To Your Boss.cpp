#include<bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int N,M;
	while(cin >> N >> M){
		vector<vector<int>> relation(N+1);
		vector<string> D(N+1);
		int tmp;
		
		for(int i=2 ; i<=N ; ++i){
			cin >> tmp;
			relation[tmp].push_back(i);
		}		
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			for(int i=0 ; i<relation[cur].size() ; ++i){
				D[relation[cur][i]].assign(D[cur].begin(),D[cur].end());
				D[relation[cur][i]]+=i;
				q.push(relation[cur][i]);
			}
		}
		int a,b;
		string v;
		for(int i=0 ; i<M ; ++i){
			cin >> a >> b;
			v.assign(D[a].begin(),D[a].begin()+D[b].size());
			if(D[b] == v) cout << "No\n";
			else cout << "Yes\n";
		}
	}
	return 0;
}
