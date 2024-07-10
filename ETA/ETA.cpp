#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll a,b;
	char c;
	while(cin >> a >> c >> b){
		if(a < b-1){
			cout << "impossible\n";
			continue;
		}
		ll t=a,v=b,cnt=1;
		while((v-1)*v/2 < t){
			++cnt;
			t=a*cnt;
			v=b*cnt;
		}
		vector<ll> rec;
		ll cur_n=0,cur_t=t,cur_v=v;
		while(cur_v){
			rec.push_back(cur_n);
			cur_t-=cur_n;
			cur_v-=1;
			if((cur_n+1)*cur_v <= cur_t) ++cur_n;
		}
		//for(ll i=0 ; i<v ; ++i) cout << rec[i] << " ";
		//cout << endl;
		cout << v << " " << v-1 << endl;
		ll n=1,id=1;
		for(ll i=2 ; i<=v ; ++i){
			cout << i << " " << n << endl;
			if(id+1<v && rec[id+1] != rec[id]) n=i;
			++id;
		}
	}
}
