#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> rec;

ll no_two_consec(ll N,ll M){
	if(rec[N]) return rec[N]; 
	rec[N]=(no_two_consec(N-2,M)%M+no_two_consec(N-1,M)%M)%M;
	return rec[N];
}

ll gcd(ll a, ll b);
 
// To compute x raised to power y under modulo M
ll power(ll x, ll y, ll M);

ll modInverse(ll A, ll M){
    ll g = gcd(A, M);
    if (g != 1)
        return 0;
    else {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        return power(A, M - 2, M);
    }
}
 
// To compute x^y under modulo m
ll power(ll x, ll y, ll M){
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
 
// Function to return gcd of a and b
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


int main(){
	cout.sync_with_stdio(false);
	ll k;
	while(cin >> k){
		for(ll i=0 ; i<k ; ++i){		
			ll N,M;
			cin >> N >> M;
			vector<ll> tmp;
			tmp.swap(rec);
			rec.resize(N+1);
			rec[1]=2;
			rec[2]=3;
			for(int i=3 ; i<=N ; ++i) rec[i]=(rec[i-1]+rec[i-2])%M;
			if(N%2){
				cout << rec[N] << endl;
			}
			else{
				ll result=0; 
				ll a=1,b=1,cnt_a=0,cnt_b=0;
				for(ll i=N/2+1 ; i<=N ; ++i){
					ll tmp=i;
					while(!(tmp%M)){
						tmp/=M;
						++cnt_a;
					} 
					a*=tmp;
					a%=M;
				}
				for(ll i=1 ; i<=N/2 ; ++i){
					ll tmp=i;
					while(!(tmp%M)){
						tmp/=M;
						++cnt_b;
					} 
					b*=tmp;
					b%=M;
				}
				if(cnt_a>cnt_b) result=0;
				else{
					ll inv=modInverse(b,M);
					result+=a*inv;
				}
        		result%=M;
        		result+=rec[N];
        		result%=M;
        		result-=((N/2)+1)%M;
        		
        		if(result < 0) result+=M;
        		cout << result << endl;
			}
		}
	}
} 
