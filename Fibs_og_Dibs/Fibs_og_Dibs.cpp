#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N=1000000007;

ll Fib(ll k){
    ll a=1,b=1,c=1,d=0;
    ll result_a=1,result_b=0,result_c=0,result_d=1;
    while(k){
        ll tmp_a=a,tmp_b=b,tmp_c=c,tmp_d=d;
        ll r_a=result_a,r_b=result_b,r_c=result_c,r_d=result_d;
        if(k%2){
            result_a=(r_a*tmp_a)%N+(r_b*tmp_c)%N;
            result_a%=N;
            result_b=(r_a*tmp_b)%N+(r_b*tmp_d)%N;
            result_b%=N;
            result_c=(r_c*tmp_a)%N+(r_d*tmp_c)%N;
            result_c%=N;
            result_d=(r_c*tmp_b)%N+(r_d*tmp_d)%N;
            result_d%=N;
        }
        a=(tmp_a*tmp_a)%N+(tmp_b*tmp_c)%N;
        a%=N;
        b=(tmp_a*tmp_b)%N+(tmp_b*tmp_d)%N;
        b%=N;
        c=(tmp_a*tmp_c)%N+(tmp_c*tmp_d)%N;
        c%=N;
        d=(tmp_b*tmp_c)%N+(tmp_d*tmp_d)%N;
        d%=N;
        k/=2;
    }
    return result_d;
}

int main(){
    ll a,b,n;
    while(cin >> a >> b >> n){
        a%=N;
        b%=N;
        if(!n) cout << a << ' ' << b << endl;
        else{
            ll k1,k2,k3,k4;
            k1=Fib(2*n);
            k2=Fib(2*n+1);
            k3=k2;
            k4=Fib(2*n+2);
            //cout << "k: " << k1 << ' ' << k2 << ' ' << k3 << ' ' << k4 << endl;
            ll result_1=(a*k1)%N+(b*k2)%N,result_2=(a*k3)%N+(b*k4)%N;
            result_1%=N;
            result_2%=N;
            cout << result_1 << ' ' << result_2 << endl;
        }
    }
}
