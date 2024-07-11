#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
	return a.first.first>b.first.first;
}

int main(){
	cout.sync_with_stdio(false);
	ll n,T;
	while(cin >> n >> T){
		vector<pair<pair<ll,ll>,ll>> rec(n);
		vector<ll> m(n);
		for(ll i=0 ; i<n ; ++i){
			ll a,b,c,x,y,z;
			cin >> a >> b >> c;
			x=max(max(a,b),c);
			z=min(min(a,b),c);
			y=a+b+c-x-z;
			pair<ll,ll> p=make_pair(x,y);
			rec[i]=make_pair(p,z);
		}
		sort(rec.begin(),rec.end(),cmp);
		vector<ll> acu(n+1);
		for(ll i=0 ; i<n ; ++i){
			acu[n-i-1]=acu[n-i]+rec[n-i-1].second;
		}
		ll cur_wid=0,cur_t=0;
		if(acu[0] > T){
			cout << "Omogulegt!\n";
			continue;
		}
		for(ll i=0 ; i<n ; ++i){
			if(cur_wid > rec[i].first.first) break;
			if(cur_t+rec[i].first.first+acu[i+1] <= T){
				cur_t+=rec[i].first.first;
				cur_wid=max(cur_wid,rec[i].first.second);
			}
			else{
				cur_t+=rec[i].second;
				cur_wid=rec[i].first.first;
			}
		}
		//cout << acu[2] << endl;
		//for(int i=0 ; i<n ; ++i) cout << rec[i].first.second << endl;
		cout << cur_wid << endl;
	}
}
