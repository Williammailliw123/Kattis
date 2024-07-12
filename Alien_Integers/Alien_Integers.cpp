#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N;
    while(cin >> N){
        vector<ll> dec;
        vector<bool> rec(10,1);
        ll tmp=N;
        while(tmp){
            dec.push_back(tmp%10);
            rec[tmp%10]=0;
            tmp/=10;
        }
        bool imp=1,zero=0;
        if(rec[0]) zero=1;
        for(ll i=0 ; i<10 ; ++i){
            if(rec[i]) imp=0;
            if(i && rec[i]) zero=0;
        }
        if(imp) cout << "impossible\n";
        else if(zero) cout << "0\n";
        else{
            bool zero_avl=0;
            if(rec[0]) zero_avl=1;
            ll small,big,dig=dec.size();
            for(ll i=1 ; i<10 ; ++i){
                if(rec[i]){
                    small=i;
                    break;
                }
            }
            for(ll i=9 ; i>=0 ; --i){
                if(rec[i]){
                    big=i;
                    break;
                }
            }
            ll greater=0,smaller=0;
            if(dec[dig-1]>big){
                greater+=small*ll(round(pow(10,dig)));
                //cout << greater << endl;
                if(!zero_avl){
                    for(ll i=0 ; i<dig ; ++i) greater+=small*ll(round(pow(10,i)));
                }
            }
            else{
                ll B;
                for(ll i=dec[dig-1]+1 ; i<10 ; ++i){
                    if(rec[i]){
                        B=i;
                        break;
                    }
                }
                //cout << greater << "+" << B*pow(10,dig-1) << "=" << greater+B*pow(10,dig-1) << endl;
                greater=greater+B*ll(round(pow(10,dig-1)));
                //cout << B << " " << dig-1 << " " << B*pow(10,dig-1) << endl;
                if(!zero_avl){
                    for(ll i=0 ; i<dig-1 ; ++i){
                        //cout << greater << endl;
                        greater+=small*ll(round(pow(10,i)));
                    }
                }
            }
            if(dec[dig-1]<small){
                smaller+=big*ll(round(pow(10,dig-2)));
                for(ll i=0 ; i<dig-2 ; ++i) smaller+=big*ll(round(pow(10,i)));
            }
            else{
                ll S;
                for(ll i=dec[dig-1]-1 ; i>=0 ; --i){
                    if(rec[i]){
                        S=i;
                        break;
                    }
                }
                smaller+=S*ll(round(pow(10,dig-1)));
                for(ll i=0 ; i<dig-1 ; ++i) smaller+=big*ll(round(pow(10,i)));
            }
            //cout << "smaller: " << smaller << " greater: " << greater << endl;
            if((N-smaller) < (greater-N)) cout << smaller << endl;
            else if((N-smaller) > (greater-N)) cout << greater << endl;
            else cout << smaller << " " << greater << endl;
        }
    }
}