#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
vector<vector<int>> rec;
vector<int> cnt;

int F(int lev,int state){
	if(lev == n) return 100000000;
	int result=0,cur=state;
	if(cnt[state]) return cnt[state];
	for(int i=0 ; i<n ; ++i){
		if(cur%2 == 0){
			int tmp=min(rec[lev][i],F(lev+1,state+pow(2,i)));
			if(tmp > result) result=tmp;
		}
		cur/=2;
	}
	cnt[state]=result;
	return cnt[state];
}

int main(){
	cout.sync_with_stdio(false);
	while(cin >> n){
		vector<int> tmp(n);
		rec.clear();
		rec.resize(n,tmp);
		cnt.clear();
		cnt.resize(pow(2,n));
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<n ; ++j) cin >> rec[i][j];
		}
		string S;
		for(int i=0 ; i<n ; ++i) S.push_back('0');
		int num=F(0,0);
		cout << num << endl;
	}
}
