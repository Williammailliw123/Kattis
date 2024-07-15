#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll T;
    while(cin >> T){
        for(ll i=0 ; i<T ; ++i){
            ll n;
            cin >> n;
            vector<ll> small,big;
            for(ll j=1 ; j<=round(sqrt(n)) ; ++j){
                if(!(n%j)){
                    if(j*j == n) small.push_back(j);
                    else{
                        small.push_back(j);
                        big.push_back(n/j);
                    }
                }
            }
            bool fail=0;
            ll cover=0;
            for(ll j=0 ; j<small.size() && !fail ; ++j){
                if(cover<small[j]-1) fail=1;
                cover+=small[j];
            }
            for(ll j=big.size()-1 ; j>=0 && !fail ; --j){
                if(cover<big[j]-1) fail=1;
                cover+=big[j];
            }
            if(fail) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}