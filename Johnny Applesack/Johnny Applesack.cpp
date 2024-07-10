#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,K;
	while(cin >> N >> K){
		int result=0;
		while(1){
			if(N<=K){
				result+=N;
				break;
			}
			else{
				++result;
				if(N%K) N-=(N/K)+1;
				else N-=(N/K);
			}
		}
		cout << result+1 << endl;
	}
	return 0;
}
