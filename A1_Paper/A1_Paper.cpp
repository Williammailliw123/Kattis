#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n;
    while(cin >> n){
        vector<ll> rec(n+1);
        for(int i=2 ; i<=n ; ++i) cin >> rec[i];
        ll tot=pow(2,n-1);
        ll cum=0;
        for(int i=2 ; i<=n ; ++i) cum+=rec[i]*pow(2,n-i);
        if(cum < tot){
            cout << "impossible\n";
            continue;
        }
        int cnt=1;
        ll rem=tot,cum_odd=0,cum_even=0;
        ll m_even,m_odd;
        if(n%2){
            m_odd=n;
            m_even=n-1;
        }
        else{
            m_even=n;
            m_odd=n-1;
        }
        for(int i=2 ; i<=n ; ++i){
            if(rem <= rec[i]*pow(2,n-i)){
                ll num=rem/pow(2,n-i);
                if(i%2) cum_odd+=num*pow(2,(m_odd-i)/2);
                else cum_even+=num*pow(2,(m_even-i)/2);
                break;
            }
            else{
                if(i%2) cum_odd+=rec[i]*pow(2,(m_odd-i)/2);
                else cum_even+=rec[i]*pow(2,(m_even-i)/2);
                rem-=rec[i]*pow(2,n-i);
            }
        }
        //cout << cum_odd << endl << cum_even << endl;
        double result=0;
        double A2_per=pow(2,-0.75)+pow(2,-1.25);
        double A3_per=pow(2,-1.25)+pow(2,-1.75);
        ll rem_even=cum_even,rem_odd=cum_odd;
        for(int i=2 ; i<=n ; i+=2){
            ll cur=rem_even/pow(2,(m_even-i)/2);
            rem_even%=ll(pow(2,(m_even-i)/2));
            result+=cur*A2_per*pow(2,(2-i)/2);
            if(!rem_even) break;
        }
        //cout << result << endl; 
        for(int i=3 ; i<=n ; i+=2){
            ll cur=rem_odd/pow(2,(m_odd-i)/2);
            rem_odd%=ll(pow(2,(m_odd-i)/2));
            result+=cur*A3_per*pow(2,(3-i)/2);
        }
        result-=A2_per*sqrt(2);
        cout << setprecision(15) << result << endl;
    }
}
