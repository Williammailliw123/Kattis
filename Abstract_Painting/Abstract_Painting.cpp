#include<bits/stdc++.h>
#define N 1000000007
using namespace std;
typedef long long int ll;

int main(){
    ll T;
    while(cin >> T){
        for(ll k=0 ; k<T ; ++k){
            ll R,C;
            cin >> R >> C;
            ll result=1;
            for(ll i=1 ; i<=R ; ++i){
                for(ll j=1 ; j<=C ; ++j){
                    if(i == 1 && j == 1) result*=18;
                    else if(i == 1 || j == 1) result*=6;
                    else result*=2;
                    result%=N;
                }
            }
            cout << result << endl;
        }
    }
}