#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first || a.first == b.first && a.second < b.second;
}

int main(){
	int n;
	while(cin >> n){
		for(int i=1 ; i<n+1 ; ++i){
			vector<int> value(36);
			for(int j=0 ; j<36 ; ++j) cin >> value[j];
			int m;
			cin >> m;
			vector<int> D(m);
			for(int j=0 ; j<m ; ++j) cin >> D[j];
			vector<pair<int,int>> tmp(35);
			vector<vector<pair<int,int>>> cost(m,tmp);
			for(int j=0 ; j<m ; ++j){				
				for(int k=0 ; k<35 ; ++k){
					int cur=D[j];
					int base=k+2;
					int C=0;
					while(cur){
						C+=value[cur%base];
						cur/=base;
					}
					cost[j][k]=make_pair(C,base);
				}
				sort(cost[j].begin(),cost[j].end(),cmp);
			}
			cout << "Case " << i << ":\n";
			for(int j=0 ; j<m ; ++j){
				cout << "Cheapest base(s) for number " << D[j] << ":";
				for(int k=0 ; k<35 ; ++k){
					if(cost[j][k].first != cost[j][0].first) break;
					cout << " " << cost[j][k].second;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
