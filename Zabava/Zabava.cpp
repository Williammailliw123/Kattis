#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp(const ll &a,const ll &b){
    return a>=b;
}

int main(){
    ll N,M,K;
    while(cin >> N >> M >> K){
        vector<ll> cnt(M+1);
        for(ll i=0 ; i<N ; ++i){
            ll tmp;
            cin >> tmp;
            ++cnt[tmp];
        }
        vector<ll> num(1000001);
        for(ll i=1 ; i<=1000000 ; ++i) num[i]=num[i-1]+i;
        vector<ll> decrease;
        for(ll i=1 ; i<=M ; ++i){
            ll cur_tot=num[cnt[i]],cur_cnt=cnt[i];
            for(ll j=1 ; j<=min(cur_cnt-1,K) ; ++j){
                ll t=(j+1)*num[cur_cnt/(j+1)]+(cur_cnt%(j+1))*(cur_cnt/(j+1)+1);
                decrease.push_back(cur_tot-t);
                cur_tot=t;
            }
        }
        sort(decrease.begin(),decrease.end(),cmp);
        ll result=0;
        for(ll i=1 ; i<=M ; ++i) result+=num[cnt[i]];
        ll s=decrease.size();
        for(ll i=0 ; i<min(K,s) ; ++i) result-=decrease[i];
        cout << result << endl;
    }
}