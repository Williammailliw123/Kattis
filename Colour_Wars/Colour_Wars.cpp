#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll N;
	while(cin >> N){
		vector<ll> record(10001);
		for(ll i=0 ; i<N ; ++i){
			ll tmp;
			cin >> tmp;
			record[tmp]++;
		}
		ll result=0;
		for(ll i=1 ; i<=10000 ; ++i){
			if(!record[i]) continue;
			if(!(record[i]%(i+1))) result+=record[i];
			else result+=(i+1)*(record[i]/(i+1)+1);
		}
		cout << result << endl;
	}
}
