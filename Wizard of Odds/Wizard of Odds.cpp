#include<bits/stdc++.h>
using namespace std;

int main(){
	double N,K;
	while(cin >> N >> K){
		double tmp=pow(2,K);
		if(tmp >= N) cout << "Your wish is granted!\n";
		else cout << "You will become a flying monkey!";
	}
	return 0;
}
