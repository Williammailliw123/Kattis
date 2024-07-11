#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

pair<ll,ll> N1,N2;

vector<pair<ll,ll>> find_rate(vector<pair<ll,ll>> five){
	for(int i=0 ; i<4 ; ++i){
		for(int j=i+1 ; j<5 ; ++j){
			ll x=five[i].first-five[j].first,y=five[i].second-five[j].second;
			for(int k=0 ; k<5 ; ++k){
				if(k == i || k == j) continue;
				ll a=five[i].first-five[k].first , b=five[i].second-five[k].second;
				if(a*y == b*x){
					N1=five[i];
					vector<pair<ll,ll>> result;
					result.push_back(make_pair(x,y));
					for(int l=0 ; l<5 ; ++l){
						ll aa=five[i].first-five[l].first , bb=five[i].second-five[l].second;
						if(aa*y != bb*x) result.push_back(make_pair(five[l].first,five[l].second));
					}
					return result;
				}
			}
		}
	}
	vector<pair<ll,ll>> result;
	return result;
}


int main(){
	ll N;
	cout.sync_with_stdio(false);
	while(cin >> N){
		if(N <= 4){
			for(ll i=0 ; i<N ; ++i){
				ll a,b;
				cin >> a >> b;
			}
			cout << "success\n";
			continue;
		}
		vector<pair<ll,ll>> five(5);
		for(ll i=0 ; i<5 ; ++i){
			ll a,b;
			cin >> a >> b;
			five[i]=make_pair(a,b);
		}
		vector<pair<ll,ll>> tmp=find_rate(five);
		if(tmp.empty()){
			for(ll i=5 ; i<N ; ++i){
				ll a,b;
				cin >> a >> b;
			}
			cout << "failure\n";
			continue;
		}
		pair<ll,ll> rate_1=tmp[0],rate_2;
		bool N2_known=0,rate_2_known=0;
		if(tmp.size() == 2){
			N2_known=1;
			N2=tmp[1];
		}
		else if(tmp.size() == 3){
			N2_known=1;
			rate_2_known=1;
			N2=tmp[1];
			rate_2=make_pair(tmp[1].first-tmp[2].first,tmp[1].second-tmp[2].second);
		}
		ll i;
		for(i=5 ; i<N ; ++i){
			ll a,b;
			cin >> a >> b;
			if((a-N1.first)*rate_1.second == (b-N1.second)*rate_1.first) continue;
			if(!N2_known){
				N2_known=1;
				N2=make_pair(a,b);
				continue;
			}
			if(!rate_2_known){
				rate_2_known=1;
				rate_2=make_pair(a-N2.first,b-N2.second);
				continue;
			}
			if((a-N2.first)*rate_2.second == (b-N2.second)*rate_2.first) continue;
			cout << "failure\n";
			break;
		}
		for(int j=i ; j<N ; ++j){
			ll a,b;
			cin >> a >> b;
		}
		if(i == N) cout << "success\n";
	}
}
