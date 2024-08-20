#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<ll>> combination;
ll P=1000000007;

ll comb(ll a,ll b){
    if(combination[a][b]) return combination[a][b];
    else if(a == b || !b) return combination[a][b]=1;
    else return combination[a][b]=(comb(a-1,b)+comb(a-1,b-1))%P;
}

int main(){
    ll n,k;
    while(cin >> n >> k){
        ll tmp;
        for(int i=0 ; i<n-1 ; ++i) cin >> tmp;
        vector<vector<ll>> ().swap(combination);
        combination.resize(2501,vector<ll> (2501));
        ll result=0;
        bool flag=0;
        for(int i=k ; i>=2 ; --i){
            ll cur=comb(k,i);
            cur*=i;
            cur%=P;
            for(int j=0 ; j<n-1 ; ++j){
                cur*=(i-1);
                cur%=P;
            }
            if(!flag){
                result+=cur;
                result%=P;
                flag=1;
            }
            else{
                result+=P-cur;
                result%=P;
                flag=0;
            }
        }
        cout << result << endl;
    }
}
