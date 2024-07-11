#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	cout.sync_with_stdio(false);
	ll N,B;
	while(cin >> N >> B){
		vector<ll> rec(N);
		ll loc;
		for(ll i=0 ; i<N ; ++i){
			cin >> rec[i];
			if(rec[i] == B) loc=i;
		}
		ll result=0,tmp=0;
		vector<ll> right(200001),left(200001);
		right[100000]=1;
		left[100000]=1;
		for(ll i=loc+1 ; i<N ; ++i){
			if(rec[i] > B) ++tmp;
			else --tmp;
			//if(!tmp) ++result;
			right[tmp+100000]++;
		}
		tmp=0;
		for(ll i=loc-1 ; i>=0 ; --i){
			if(rec[i] > B) ++tmp;
			else --tmp;
			//if(!tmp) ++result;
			left[tmp+100000]++;
		}
		result+=right[100000]*left[100000];
		for(ll i=1 ; i<=100000 ; ++i){
			result+=right[100000+i]*left[100000-i];
			result+=right[100000-i]*left[100000+i];
		}
		cout << result << endl;
	}
}
