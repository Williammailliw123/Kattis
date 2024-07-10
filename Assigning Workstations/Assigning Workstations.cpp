#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		vector<pair<int,int>> D(n);
		for(int i=0 ; i<n ; ++i) cin >> D[i].first >> D[i].second;
		sort(D.begin(),D.end(),cmp);
		priority_queue<pi, vector<pi>, greater<pi>> P;
		int result=0;
		for(int i=0 ; i<n ; ++i){
			if(P.empty() || D[i].first < P.top().first){
				++result;
				P.push(make_pair(D[i].first+D[i].second , D[i].first+D[i].second+m));
			}
			else if(D[i].first > P.top().second){
				while(!P.empty() && D[i].first > P.top().second) P.pop();
				if(P.empty() || D[i].first < P.top().first){					
					++result;
					P.push(make_pair(D[i].first+D[i].second , D[i].first+D[i].second+m));
				}
				else{
					P.pop();
					P.push(make_pair(D[i].first+D[i].second , D[i].first+D[i].second+m));
				}
			}
			else{
				P.pop();
				P.push(make_pair(D[i].first+D[i].second , D[i].first+D[i].second+m));
			}
		}
		cout << n-result << endl;
	}
	return 0;
} 
