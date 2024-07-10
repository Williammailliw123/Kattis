#include<bits/stdc++.h>
using namespace std;

int main(){
	int C;
	while(cin >> C){
		for(int i=1 ; i<=C ; ++i){
			string S,T;
			cin >> S >> T;
			int S_one=0,S_zero=0,S_q=0,T_one=0,T_zero=0,zero_to_one=0,one_to_zero=0;
			for(int j=0 ; j<S.size() ; ++j){
				if(S[j] == '0') S_zero++;
				else if(S[j] == '1') S_one++;
				else S_q++;
				if(T[j] == '0') T_zero++;
				else T_one++;
				if(S[j] == '0' && T[j] == '1') zero_to_one++;
				else if(S[j] == '1' && T[j] == '0') one_to_zero++;
			}
			int result=0;
			if(S_one > T_one){
				cout << "Case " << i << ": -1\n";
				continue; 
			}
			else result=max(zero_to_one,one_to_zero) + S_q;
			cout << "Case " << i << ": " << result << endl;
		}
	}
}
