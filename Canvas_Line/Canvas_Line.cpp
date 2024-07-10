#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;
	while(cin >> n){
		vector<pair<ll,ll>> data(n);
		for(ll i=0 ; i<n ; ++i){
			ll l,r;
			cin >> l >> r;
			data[i]=make_pair(l,r);
		}
		ll p;
		vector<ll> deg_loc(p);
		set<ll> S;
		cin >> p;
		for(ll i=0 ; i<p ; ++i){
			cin >> deg_loc[i];
			S.insert(deg_loc[i]);
		}
		vector<ll> deg_num(n,0);
		ll deg_id=0;
		bool imp=0;
		for(ll i=0 ; i<n ; ++i){
			ll left=data[i].first,right=data[i].second;
			while(deg_id<p && deg_loc[deg_id] < left) ++deg_id;
			while(deg_id<p && deg_loc[deg_id]<=right){
				++deg_id;
				++deg_num[i];
			}	
			if(deg_id>0) --deg_id;
			if(deg_num[i]>2) imp=1;
		}
		if(imp){
			cout << "impossible\n";
			continue;
		}
		vector<ll> result;
		for(ll i=0 ; i<n ; ++i){
			//cout << "pig\n";
			if(deg_num[i] == 2) continue;
			else if(deg_num[i] == 1){
				if(S.find(data[i].second) == S.end() &&
				   i != n-1 && (data[i+1].first == data[i].second) && deg_num[i+1] < 2){
					result.push_back(data[i].second);
					++deg_num[i+1];
				}
				else if(S.find(data[i].second) != S.end() || 
				   i != n-1 && (data[i+1].first == data[i].second) && deg_num[i+1] == 2){
					if(S.find(data[i].second-1) == S.end()) result.push_back(data[i].second-1);
					else result.push_back(data[i].second-2);
				   }
				else{
					result.push_back(data[i].second);
				}
			}
			else{
				result.push_back(data[i].first+1);
				if(S.find(data[i].second) == S.end() &&
				   i != n-1 && (data[i+1].first == data[i].second) && deg_num[i+1] < 2){
					result.push_back(data[i].second);
					++deg_num[i+1];
				}
				else if(S.find(data[i].second) != S.end() || 
				   i != n-1 && (data[i+1].first == data[i].second) && deg_num[i+1] == 2){
					if(S.find(data[i].second-1) == S.end()) result.push_back(data[i].second-1);
					else result.push_back(data[i].second-2);
				   } 
				else{
					result.push_back(data[i].second);
				}
			}
		}
		cout << result.size() << endl;
		for(ll i=0 ; i<result.size() ; ++i){
			if(i == result.size()-1) cout << result[i];
			else cout << result[i] << " ";
		}
		cout << endl;
	}
}
