#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second < b.second || a.second == b.second && a.first < b.first;
}

int main(){
	int N,M;
	while(cin >> N){
		vector<pair<int,int>> D(N);
		for(int i=0 ; i<N ; ++i){
			D[i].first=i+1;
			cin >> D[i].second;
		}
		vector<pair<int,int>> org_D=D;
		cin >> M;
		int a,b;
		for(int i=0 ; i<M ; ++i){
			cin >> a >> b;
			D[a-1].second += org_D[b-1].second;
			D[b-1].second += org_D[a-1].second;
		}
		sort(D.begin(),D.end(),cmp);
		cout << D[0].first << endl;
	}
	return 0;
} 
