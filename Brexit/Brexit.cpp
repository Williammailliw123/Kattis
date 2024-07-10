#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C,P,X,L;
	while(cin >> C >> P >> X >> L){
		vector<vector<int>> relation(C+1);
		int a,b;
		for(int i=0 ; i<P ; ++i){
			cin >> a >> b;
			relation[a].push_back(b);
			relation[b].push_back(a);
		}
		vector<bool> quit(C+1);
		vector<int> status(C+1);
		for(int i=1 ; i<C+1 ; ++i) status[i]=relation[i].size();
		queue<int> q;
		q.push(L);
		quit[L]=1;
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			for(int i=0 ; i<relation[cur].size() ; ++i){
				if(quit[relation[cur][i]]) continue;
				if(status[relation[cur][i]]<=2){
					q.push(relation[cur][i]);
					quit[relation[cur][i]]=1;
				}
				else status[relation[cur][i]]-=2;
			}
		}
		if(quit[X]) cout << "leave\n";
		else cout << "stay\n";
	}
	return 0;
}
