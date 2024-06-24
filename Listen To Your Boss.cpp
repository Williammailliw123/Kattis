#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> relation;
vector<int> time_in,time_out;
int T;

void DFS(int cur){
	time_in[cur]=T;
	for(int i=0 ; i<relation[cur].size() ; ++i){		
		++T;
		DFS(relation[cur][i]);
	}
	++T;
	time_out[cur]=T;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,M;
	while(cin >> N >> M){
		relation.clear();
		relation.resize(N+1);
		time_in.clear();
		time_in.resize(N+1);
		time_out.clear();
		time_out.resize(N+1);
		T=0;
		int tmp;
		for(int i=2 ; i<=N ; ++i){
			cin >> tmp;
			relation[tmp].push_back(i);
		}
		DFS(1);
		int a,b;
		for(int i=0 ; i<M ; ++i){
			cin >> a >> b;
			if(time_in[a]>time_in[b] && time_out[a]<time_out[b]) cout << "No\n";
			else cout << "Yes\n";
		}
	}
	return 0;
}
