#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;

ll N;
string W;
map<string,ll> M_1,M_2,flag;

ll F(string S){
	if(flag.find(S) != flag.end()) return M_2[S];
	if(S.size() == 1) return 0;
	ll result=M_1[S];
	for(ll i=0 ; i<S.size()-1 ; ++i){
		result+=(M_1[S.substr(0,i+1)]%1000000007)*(F(S.substr(i+1))%1000000007);
		result%=1000000007;
	}
	M_2[S]=result;
	flag[S]=1;
	return result;
}


int main(){
	ll N;
	string W;
	while(cin >> N >> W){
		M_1.clear();
		M_2.clear();
		flag.clear();
		for(ll i=0 ; i<N ; ++i){
			string s;
			ll tmp;
			cin >> s >> tmp;
			M_1[s]=tmp;
			if(s.size() == 1){
				M_2[s]=tmp;
				flag[s]=1;
			}
		}
		cout << F(W) << endl;
	}
}
