#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	cout.sync_with_stdio(false);
	ll n,p;
	while(cin >> n >> p){
		vector<ll> record(n);
		for(ll i=0 ; i<n ; ++i) cin >> record[i];
		sort(record.begin(),record.end());
		ll loc=record[0];
		for(ll i=0 ; i<n ; ++i){
			ll tmp=record[i]-(i+1)*p;
			loc=min(loc,tmp);
		}
		ll result=record[0]-loc;
		cout << result << endl; 
	}
}
