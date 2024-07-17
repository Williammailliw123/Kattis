#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll P;
    while(cin >> P){
        for(ll i=1 ; i<=P ; ++i){
            ll id,LEFT,RIGHT;
            char c;
            cin >> id >> LEFT >> c >> RIGHT;
            vector<pair<bool,ll>> rec;
            ll L=LEFT,R=RIGHT;
            while(L && R){
                if(L<R){
                    ll cnt=R/L;
                    R%=L;
                    rec.push_back(make_pair(0,cnt));
                }
                else{
                    ll cnt=L/R;
                    L%=R;
                    rec.push_back(make_pair(1,cnt));
                }
            }
            if(LEFT == 1 && RIGHT == 1) cout << i << " 1/2\n";
            else if(!rec[0].first) cout << i << " " << RIGHT << "/" << RIGHT-LEFT << endl;
            else{
                if(rec.size() == 1) cout << i << " 1/" << LEFT+1 << endl;
                else{
                    ll cnt=rec[0].second;
                    cout << i << " " << RIGHT << "/" << (2*cnt+1)*RIGHT-LEFT << endl;
                }
            }
        }
    }
}