#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll N,K,Q;
	while(cin >> N >> K >> Q){
		for(ll i=0 ; i<Q ; ++i){
			ll a,b;
			cin >> a >> b;
			vector<ll> rec_a,rec_b;
			ll tmp=a;
			while(tmp != 1){
				rec_a.push_back(tmp);
				tmp=(tmp+K-2)/K;
			}
			rec_a.push_back(1);
			tmp=b;
			while(tmp != 1){
				rec_b.push_back(tmp);
				tmp=(tmp+K-2)/K;
			}
			rec_b.push_back(1);			
			ll lca=0,dep_a=rec_a.size()-1,dep_b=rec_b.size()-1;
			while(lca<=dep_a && lca<=dep_b && rec_a[dep_a-lca] == rec_b[dep_b-lca]) ++lca;
			ll result=dep_a+dep_b-2*lca+2;
			cout << result << endl;
		}
	}
}
