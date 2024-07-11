#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;

int main(){
    ll N,M,K;
    while(cin >> N >> M >> K){
        vector<ll> init_bal(N);
        for(ll i=0 ; i<N ; ++i) cin >> init_bal[i];
        vector<vector<ll>> in(N);
        vector<ll> in_sum;
        in_sum=init_bal;
        for(ll i=0 ; i<M ; ++i){
            ll a,b;
            cin >> a >> b;
            in[b].push_back(in_sum[a]);
            vector<ll> ().swap(in[a]);
            in_sum[b]+=in_sum[a];
            in_sum[a]=0;
        }
        vector<ll> data;
        for(ll i=0 ; i<N ; ++i){
            for(ll j=0 ; j<in[i].size() ; ++j){
                data.push_back(in[i][j]);
            }
        }
        sort(data.begin(),data.end(),greater<ll>());
        ll result=0,s=data.size();
        for(ll i=0 ; i<min(K,s) ; ++i) result+=data[i];
        cout << result << endl;
    }
}
