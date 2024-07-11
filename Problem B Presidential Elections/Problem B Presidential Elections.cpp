#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct area{
	int D,C,F,U,N;
	area(int a,int b,int c,int d){
		D=a;C=b;F=c;U=d;
		N=(F+U-C)/2+1;
	}
};
vector<area> A;
vector<vector<int>> dp;

int cal(int n,int diff){
	if(diff>0) return 0;
	if(n<0) return INF;
	if(dp[n][-diff]) return dp[n][-diff];
	return dp[n][-diff] = min(cal(n-1,diff) , cal(n-1,diff+A[n].D*2)+A[n].N);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int S,result;
	while(cin >> S){
		A.clear();
		int diff=0,D,C,F,U,tmp=0;
		for(int i=0 ; i<S ; ++i){
			cin >> D >> C >> F >> U;
			if(C > F+U) diff+=D;
			else if(F >= C+U) diff-=D;
			else{
				tmp+=D;
				A.push_back(area(D,C,F,U));
			}
		}
		if(diff+tmp<=0) cout << "impossible\n";
		else if(diff-tmp>0) cout << 0 << endl;
		else{
			diff-=tmp;
			vector<int> tmp(2017);
			dp.resize(A.size(),tmp);
			result=cal(A.size()-1,diff);
			cout << result << endl;
		}
	}
	return 0;
}
