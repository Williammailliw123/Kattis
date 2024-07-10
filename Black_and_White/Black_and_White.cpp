#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<double> rat(n);
        for(int i=0 ; i<n ; ++i) cin >> rat[i];
        vector<double> rec(pow(2,n));
        for(int i=0 ; i<pow(2,n) ; ++i){
            vector<bool> bit_str(n,0);
            int cnt=0,tmp=i;
            for(int j=0 ; j<n && tmp ; ++j){
                if(tmp%2){
                    bit_str[j]=1;
                    ++cnt;
                }
                tmp/=2;
            }
            if(cnt<=2){
                rec[i]=0;
                continue;
            }
            double tot=0,pos=1,neg=1;
            vector<double> part(n);
            for(int j=0 ; j<n ; ++j){
                if(bit_str[j]){
                    pos*=rat[j];
                    neg*=(1.0-rat[j]);
                }
            }
            for(int j=0 ; j<n ; ++j){
                if(bit_str[j]){
                    part[j]=rat[j]*(neg/(1.0-rat[j]))+(1.0-rat[j])*(pos/rat[j]);
                    tot+=part[j];
                }
            }
            double result=1.0/tot;
            for(int j=0 ; j<n ; ++j){
                if(bit_str[j]){
                    result+=(part[j]/tot)*rec[i-pow(2,j)];
                }
            }
            rec[i]=result;
        }
        cout << setprecision(15) << rec[pow(2,n)-1] << endl;
    }
}
