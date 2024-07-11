#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> div(string a,ll b){
	ll r = 0;
	vector<ll> c(a.size());
	for(ll i=0; i<a.size(); ++i){
		ll cur=a[i]-'0';
		//cout << cur << endl; 
		r = r * 10 + cur;
		c[i] = r / b;
		r %= b;
	}
	return c;
}


int main(){
	string s;
	while(cin >> s){
		if(s == "0"){
			cout << 0 << endl;
			continue;
		}
		ll big=s.size(),cnt=1;
		while(1){			
			ll small=0,tmp=cnt;
			deque<ll> rec;
			while(1){
				rec.push_front(tmp%10);
				tmp/=10;
				++small;
				if(!tmp) break;
			}
			//for(ll i=0 ; i<rec.size() ; ++i) cout << rec[i];
			//cout << endl;
			if(small+cnt-1<big){
				++cnt;
				continue;
			}
			else if(small+cnt-1>big){
				--cnt;
				break;
			}
			else if(small+cnt-1==big){
				ll keep=0;
				for(ll i=0 ; i<small ; ++i){
					ll cur=s[i]-'0';
					if(rec[i] == cur) continue;
					else if(rec[i]>cur){
						--cnt;
						break;
					}
					else if(rec[i]<cur){
						++cnt;
						keep=1;
						break;
					}
				}
				if(!keep) break;
			}
		}
		vector<ll> result=div(s,cnt);
		ll id;
		for(id=0 ; id<result.size() ; ++id) if(result[id]) break;
		for(;id<result.size() ; ++id) cout << result[id];
		cout << endl; 
	}
}

