#include<bits/stdc++.h>
using namespace std;

int main(){
	double n;
	while(cin >> n){
		double tmp=1;
		while(tmp*18 < n){
			tmp*=18;
		}
		if(tmp*9 >= n) cout << "Stan wins.\n";
		else cout << "Ollie wins.\n";
	}
	return 0;
}
