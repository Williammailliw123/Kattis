#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll N;
	while(cin >> N){
		vector<ll> weight(N);
		ll sum=0;
		for(ll i=0 ; i<N ; ++i){
			cin >> weight[i];
			sum+=weight[i];
		}
		ll result=0;
		if(N>=4){
			vector<ll> C(N+1);
			C[3]=N*(N-1)*(N-2)/6;
			ll num=0;
			for(ll i=4 ; i<=N ; ++i){
				C[i]=C[i-1]*(N-i+1)/i;
				num+=i*C[i];
			}
			num/=N;
			result+=sum*num;
		}
		if(N>=3){
			for(ll i=0 ; i<N-2 ; ++i){
				for(ll j=i+1 ; j<N-1 ; ++j){
					for(ll k=j+1 ; k<N ; ++k){
						ll w=weight[i]+weight[j]+weight[k];
						if(w>=200) result+=w;
					}
				}
			}
		}
		if(N>=2){
			for(ll i=0 ; i<N-1 ; ++i){
				for(ll j=i+1 ; j<N ; ++j){
					ll w=weight[i]+weight[j];
					if(w>=200) result+=w;
				}
			}
		}
		for(ll i=0 ; i<N ; ++i) if(weight[i]>=200) result+=weight[i];
		cout << result << endl;
	}
}
