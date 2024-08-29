#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first < b.first;
}

int main(){
    ll n,B;
    while(cin >> n >> B){
        vector<pair<ll,ll>> rec(n);
        ll tot=0;
        for(ll i=0 ; i<n ; ++i){
            ll a,vol;
            cin >> a;
            if(!(a%B)) vol=a;
            else vol=(a/B+1)*B;
            tot+=vol;
            rec[i]=make_pair(vol,i);
        }
        sort(rec.begin(),rec.end(),cmp);
        vector<ll> result(n);
        ll cur=0,rem=tot;
        ll cnt_one=0;
        for(ll i=n-1 ; i>=0 && cnt_one<=1; --i){
            ll vol=rec[i].first,id=rec[i].second;
            rem-=vol;
            if(cur-rem <= vol){
                ++cnt_one;
                result[id]=1;
            }
            else result[id]=2;
            if(vol < cur) cur-=vol;
            else cur=vol-cur;
        }
        if(cnt_one > 1){
            vector<ll> ().swap(result);
            result.resize(n,1);
        }
        for(ll i=0 ; i<n ; ++i){
            if(i<n-1) cout << result[i] << ' ';
            else cout << result[i] << endl;
        }
    }
}