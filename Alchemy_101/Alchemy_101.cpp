#include<bits/stdc++.h>
using namespace std;
typedef long long short ll;

short main(){
	ll t;
	while(cin >> t){
		for(ll k=0 ; k<t ; ++k){
			ll m;			
 			cin >> m;
			vector<ll> bi;
			ll tmp=m;
			while(tmp > 0){
				bi.push_back(tmp%2);
				tmp/=2;
			}
			vector<ll> sum;
			for(ll i=0 ; i<bi.size() ; ++i) sum.push_back(0);
			for(ll i=1 ; i<=m ; ++i){
				vector<ll> v;
				ll a=i;
				while(a > 0){
					v.push_back(a%2);
					a/=2;
				}
				for(ll j=0 ; j<v.size() ; ++j){
					if(v[j] == 1){
						if(sum[j] == 0) sum[j]=1;
						else sum[j]=0;
					}
				}
			}
			ll ignore=0;
			for(ll i=0 ; i<bi.size() ; ++i){
				if(bi[i] != sum[i]) ignore+=pow(2,i);
			}
			if(!ignore) cout << m << endl;
			else cout << m-1 << endl;
			for(ll i=1 ; i<=m ; ++i){
				if(i == ignore) continue;
				cout << i << " ";
			}
			cout << endl;
		}
	}
}
