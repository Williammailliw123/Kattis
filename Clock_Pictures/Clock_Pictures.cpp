#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;
	while(cin >> n){
		vector<ll> data1(n),data2(n);
		for(ll i=0 ; i<n ; ++i) cin >> data1[i];
		for(ll i=0 ; i<n ; ++i) cin >> data2[i];
		sort(data1.begin(),data1.end());
		sort(data2.begin(),data2.end());
		vector<ll> itv1(n),itv2(n);
		for(int i=1 ; i<n ; ++i){
			itv1[i-1]=data1[i]-data1[i-1];
			itv2[i-1]=data2[i]-data2[i-1];
		}
		itv1[n-1]=data1[0]+360000-data1[n-1];
		itv2[n-1]=data2[0]+360000-data2[n-1];
		
		vector<ll> prefix(n);//KMP algorithm
		prefix[0]=0;
		for(ll i=1,pos=0 ; i<n ; ++i){
			while(pos && itv1[i] != itv1[pos]) pos=prefix[pos-1];
			if(itv1[i] == itv1[pos]) ++pos;
			prefix[i]=pos;
		}
		vector<ll> expansion=itv2;
		for(ll i=0 ; i<n ; ++i) expansion.push_back(itv2[i]);
		bool flag=0;
		for(ll i=0,pos=0 ; i<2*n && !flag ; ++i){
			while(pos && expansion[i] != itv1[pos]) pos=prefix[pos-1];
			if(expansion[i] == itv1[pos]) ++pos;
			if(pos == n){
				flag=1;
				break;
			}
		}
		if(flag) cout << "possible\n";
		else cout << "impossible\n";
	}
}
