#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll T;
	while(cin >> T){
		for(ll i=0; i<T ; ++i){
			ll N;
			cin >> N;
			vector<ll> rec(N+1);
			for(ll j=1 ; j<=N ; ++j){
				ll w;
				cin >> w;
				for(ll k=0 ; k<w ; ++k){
					ll tmp;
					cin >> tmp;
					rec[j]+=tmp;
				}
			}
			sort(rec.begin(),rec.end());
			ll r=0;
			for(ll j=1 ; j<=N ; ++j){
				r+=rec[j]*(N-j+1);
			}
			double result=double(r)/N;
			cout << fixed << setprecision(8) << result << endl;
		}
	}
}
