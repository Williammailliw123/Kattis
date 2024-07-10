#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool is_prime(ll k){
	bool result=1;
	for(ll i=2 ; i<=sqrt(k) ; ++i){
		if(k%i) continue;
		result=0;
		break;
	}
	return result;
} 

ll num_of_factor(ll n,ll f){
	ll cnt=0,p=1;
	while(pow(f,p)<=n){
		cnt+=n/pow(f,p);
		++p;
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	ll n,m;
	while(cin >> n >> m){
		if(!m){
			cout << "0 does not divide " << n << "!\n";
			continue;
		}
		vector<ll> fac;
		for(ll i=2 ; i<=sqrt(m) ; ++i){
			if(is_prime(i)) fac.push_back(i);
		}
		ll id=0,cur=m;
		vector<ll> factorization(fac.size());
		while(id<fac.size() && cur != 1){
			if(!(cur%fac[id])){
				cur/=fac[id];
				++factorization[id];
			}
			else ++id;
		}
		if(cur!=1){
			fac.push_back(cur);
			factorization.push_back(1);
		}
		//for(ll i=0 ; i<fac.size() ; ++i) cout << fac[i] << " ";
		//cout << endl;
		//for(ll i=0 ; i<factorization.size() ; ++i) cout << fac[i] << ": " << factorization[i] << endl;
		bool success=1;
		for(ll i=0 ; i<factorization.size() ; ++i){
			if(!factorization[i]) continue;
			else if(num_of_factor(n,fac[i])>=factorization[i]) continue;
			else{
				success=0;
				break;
			}
		}
		if(success) cout << m << " divides " << n << "!\n";
		else cout << m << " does not divide " << n << "!\n";
	}
}
