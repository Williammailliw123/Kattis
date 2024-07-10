#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> record;
long long result;

long long F(int N,int K,int T){
	long long R=0;
	if(T<N || T>N*K) return 0;
	if(T == N || T == N*K) return record[T][N]=1;
	if(N == 1) return record[T][N]=1;
	if(record[T][N]){
		//cout << T << " " << N << " " << record[T][N] << endl;
		return record[T][N];
	}
	for(int i=K ; i>0 ; --i){
		R+=F(N-1,K,T-i);
		R%=1000000009;
	}
	record[T][N]=R;
	return R;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int N,K,T;
	while(cin >> N >> K >> T){
		vector<long long> tmp(N+1,0);
		record.resize(T+1);
		record.assign(T+1,tmp);
		result=F(N,K,T)%1000000009;
		cout << result << endl;
	}
	return 0;
}
