#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll N;
	while(cin >> N){
		vector<ll> data(N);
		ll M=-1;
		for(ll i=0 ; i<N ; ++i){
			cin >> data[i];
			M=max(M,data[i]);
		}
		vector<ll> state(M+2,0);
		ll result=0;
		for(ll i=0 ; i<N ; ++i){
			ll cur=data[i];
			if(!state[cur+1]){
				++result;
				++state[cur];
			}
			else if(state[cur+1]){
				--state[cur+1];
				++state[cur];
			}
		}
		cout << result << endl;
	}
}
