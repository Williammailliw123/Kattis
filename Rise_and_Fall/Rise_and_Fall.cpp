#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
	ll t;
	while(cin >> t){
		vector<string> s(t);
		for(ll i=0 ; i<t ; ++i) cin >> s[i];
		for(ll i=0 ; i<t ; ++i){
			ll init=0;
			while(s[i][init] == '0'){
				cout << '0';
				++init;
			}
			if(init == s[i].size()){
				cout << 0 << endl;
				continue;
			}
			char cur=s[i][init];
			bool stage=0;
			for(ll j=init ; j<s[i].size() ; ++j){
				cout << cur;
				if(j == s[i].size()-1) break;
				else if(!stage){
					if(cur<=s[i][j+1]){
						cur=s[i][j+1];
						continue;
					}
					else{
						stage=1;
						cur=s[i][j+1];
					}
				}
				else{
					if(cur>s[i][j+1]){
						cur=s[i][j+1];
						continue;
					}
				}
			}
			cout << endl;
		}
	}
}
	

