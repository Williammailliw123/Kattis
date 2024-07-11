#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

ll gcd(ll a, ll b);
 
// To compute x raised to power y under modulo M
ll power(ll x, ll y, ll M);

ll modInverse(ll A, ll M)
{
    ll g = gcd(A, M);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        return power(A, M - 2, M);
    }
}
 
// To compute x^y under modulo m
ll power(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
 
// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main(){
    ll N,num=1000000007;
    while(cin >> N){
        ll a=1,b=1,result;
        for(ll i=1 ; i<=N ; ++i){   
            a*=2*(2*i-1);
            a%=num;
        }
        for(ll i=1 ; i<=N ; ++i){   
            b*=i+1;
            b%=num;
        }
        ll inv=modInverse(b,num);
        //cout << modInverse(7,11) << endl;
        result=a*inv;
        result%=num;
        cout << result << endl; 
    }
}


