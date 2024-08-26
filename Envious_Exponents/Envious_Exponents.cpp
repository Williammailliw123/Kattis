#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N,k;
    while(cin >> N >> k){
        vector<ll> binary;
        ll tmp=N,cnt_one=0,cnt_zero=0;
        while(tmp){
            if(tmp%2) ++cnt_one;
            else ++cnt_zero;
            binary.push_back(tmp%2);
            tmp/=2;
        }
        vector<int> result;
        if(binary.size() < k) for(int i=0 ; i<k ; ++i) result.push_back(1);
        else if(binary.size() == k){
            if(!cnt_zero){
                for(int i=0 ; i<k-1 ; ++i) result.push_back(1);
                result.push_back(0);
                result.push_back(1);
            }
            else for(int i=0 ; i<k ; ++i) result.push_back(1);
        }
        else{
            ll pre=0;
            for(ll i=binary.size()-1 ; i>=0 ; --i){
                if(binary[i]) ++pre;
                else break;
            }
            if(pre >= k){
                for(ll i=0 ; i<k-1 ; ++i) result.push_back(1);
                for(ll i=result.size() ; i<binary.size() ; ++i) result.push_back(0);
                result.push_back(1);
            }
            else{
                result.resize(binary.size());
                ll rem=k;
                for(ll i=binary.size()-1 ; i>=0 ; --i){
                	if(binary[i]){
                		result[i]=1;
                		--rem;
					}
					else{
						if(rem == i+1){
							result[i]=1;
							--rem;
							break;
						}
						if(binary[i-1]){
							ll consec=0;
							for(ll j=i-1 ; j>=0 ; --j){
								if(binary[j]) ++consec;
								else break;
							}
							if(consec >= rem){
								result[i]=1;
								--rem;
								break;
							}
						}
					}
				}
				for(ll i=0 ; i<rem ; ++i) result[i]=1;
            }
        }
        ll k=0;
        for(ll i=0 ; i<result.size() ; ++i) if(result[i]) k+=ll(pow(2,i));
        cout << k << endl;
    }
}
