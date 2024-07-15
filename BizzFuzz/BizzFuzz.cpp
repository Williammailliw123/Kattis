#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD(ll a,ll b){
    while(b){
        ll tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

vector<ll> MUL(vector<ll> arr,ll b){
    vector<ll> result(37);
    for(ll i=0 ; i<arr.size() ; ++i){
        result[i]=arr[i]*b;
    }
    for(ll i=0 ; i<result.size()-1 ; ++i){
        result[i+1]+=result[i]/10;
        result[i]%=10;
    }
    for(ll i=result.size()-1 ; i>=0 ; --i){
        if(result[i]) break;
        result.pop_back();
    }
    return result;
}

vector<ll> DIV(vector<ll> arr,ll b){
    ll r=0;
    vector<ll> result(arr.size());
    for(ll i=arr.size()-1 ; i>=0 ; --i){
        r=r*10+arr[i];
        result[i]=r/b;
        r%=b;
    }
    for(ll i=result.size()-1 ; i>=0 ; --i){
        if(result[i]) break;
        result.pop_back();
    }
    return result;
}

int main(){
    ll A,B,C,D;
    while(cin >> A >> B >> C >> D){
        ll gcd=GCD(C,D);
        vector<ll> c_arr;
        ll tmp=C;
        while(tmp){
            c_arr.push_back(tmp%10);
            tmp/=10;
        }
        vector<ll> c_mul_d=MUL(c_arr,D);
        vector<ll> lcm=DIV(c_mul_d,gcd);
        if(lcm.size() >= 19) cout << "0\n";
        else{
            ll div=0;
            for(ll i=0 ; i<lcm.size() ; ++i) div+=lcm[i]*ll(round(pow(10,i)));
            ll result=(B/div)-((A-1)/div);
            cout << result << endl;
        }
    }
}