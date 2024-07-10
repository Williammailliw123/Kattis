#include<bits/stdc++.h>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.precision(0);
	int N;
	while(cin >> N){
		vector<int> x(N),y(N);
		for(int i=0 ; i<N ; ++i) cin >> x[i] >> y[i];
		sort(x.begin(),x.end(),greater<int>());
		sort(y.begin(),y.end(),greater<int>());
		unsigned long long n=N-1,result=0;
		for(int i=0 ; i<N/2 ; ++i){
			result+=n*((x[i]-x[N-1-i])+(y[i]-y[N-1-i]));
			n-=2;
		}
		cout << result << endl;
	}
}
