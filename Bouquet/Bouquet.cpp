#include<bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> D;
vector<int> rec;

int dp(int id){
	int result=0;
	for(int i=D[id].second+1 ; i<N && i<D[id].second+2000 ; ++i){
		if(D[i].first <= id) continue;
		if(rec[i]) result=result>rec[i]?result:rec[i];
		else result=result>dp(i)?result:rec[i];
	}
	for(int i=N-1 ; i>D[i].second && i>N-1000 ; --i){
		if(D[i].first <= id) continue;
		if(rec[i]) result=result>rec[i]?result:rec[i];
		else result=result>dp(i)?result:rec[i];
	}
	return rec[id]=result+1;
}

int main(){
    while(cin >> N){
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
        vector<pair<int,int>> ().swap(D);
        D.resize(N);
        vector<int> ().swap(rec);
        rec.resize(N);
        for(int i=0 ; i<N ; ++i){
        	int l,r;
        	cin >> l >> r;
        	l=0>i-l?0:i-l;
        	r=N-1<i+r?N-1:i+r;
        	D[i]=make_pair(l,r);
		}
		int result=0;
		int least_end=N+1;
		for(int i=0 ; i<N ; ++i){
			result=result>dp(i)?result:rec[i];
		}
		cout << result << '\n';
    }
}
