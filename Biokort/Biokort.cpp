#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,m,k;
    while(cin >> n >> m >> k){
        vector<ll> cum(1000001),above;
        for(ll i=0 ; i<n ; ++i){
            string s;
            int k;
            cin >> s >> k;
            ++cum[k];
        }
        above=cum;
        for(ll i=999999 ; i>=0 ; --i) above[i]+=above[i+1];
        ll num=0,val=0;
        for(ll i=0 ; i<1000000 ; ++i){
            if(k<m*above[i+1]){
                ++num;
                val+=k;
            }
            else{
                for(int j=i+1 ; j<=1000000 ; ++j) val+=cum[j]*(j-num)*m;
                break;
            }
        }
        cout << num << ' ' << val << endl;
    }
}