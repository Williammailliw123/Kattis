#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll N;
	while(cin >> N){
		vector<vector<char>> rec;
		vector<char> tmp(N);
		rec.resize(N,tmp);
		ll cnt=0;
		vector<ll> row(N),col(N);
		
		for(ll i=0 ; i<N ; ++i){
			for(ll j=0 ; j<N ; ++j){
				cin >> rec[i][j];
				if(rec[i][j] == '1'){
					++cnt;
					++row[i];
					++col[j];
				}
			}
		}		
		ll result=0;
		for(ll i=0 ; i<N ; ++i){
			if((N-col[i])+(cnt-col[i]) <= N){
				result=1;
				break;
			}
		}
		for(ll i=0 ; i<N ; ++i){
			if((N-row[i])+(cnt-row[i]) <= N){
				if(!result) result=2;
				else if(result == 1) result=3;
				break;
			}
		}
		//cout << result << endl;
		if(result == 1) cout << "|\n";
		else if(result == 2) cout << "-\n";
		else cout << "+\n";
	}
}
