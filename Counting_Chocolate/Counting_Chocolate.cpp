#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n;
vector<ll> rec;
ll cnt;
vector<vector<ll>> available;

ll F(ll remain,ll id){
	if(available[id][remain] != -1) return available[id][remain];
	else if(id == n-1){
		if(!remain || remain == rec[id]) available[id][remain]=1;
		else available[id][remain]=0;
	}
	else if(rec[id] == remain) available[id][remain]=1;
	else if(rec[id] > remain) available[id][remain]=F(remain,id+1);
	else available[id][remain]=max(F(remain-rec[id],id+1),F(remain,id+1));
	return available[id][remain];
}


int main(){
	cout.sync_with_stdio(false);
	while(cin >> n){
		rec.clear();
		rec.resize(n);
		cnt=0;	
		for(ll i=0 ; i<n ; ++i){
			cin >> rec[i];
			cnt+=rec[i];
		}
		if(cnt%2){
			cout << "NO\n";
			continue;
		}
		cnt/=2;
		vector<ll> tmp(cnt+1,-1);
		available.clear();
		available.resize(n,tmp);
		ll result=F(cnt,0);
		if(result) cout << "YES\n";
		else cout << "NO\n";
	}
}
