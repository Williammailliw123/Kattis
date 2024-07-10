#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		vector<char> C(s.begin(),s.end());
		C.push_back('S');
		int result=0;
		char status='N';
		for(int i=0 ; i<C.size()-1 ; ++i){
			if(C[i] == 'B'){
				++result;
				continue;
			}
			else if(C[i] != status) continue;
			else{
				bool flag=0;
				for(int j=i+1 ; j<C.size() ; ++j){
					if(C[j] == 'B') continue;
					else if(C[j] == C[i]){
						flag=1;
						break;
					}
					else break;
				}
				if(flag){
					++result;
					if(status == 'N') status='S';
					else status='N';
				}
				else ++result;
			}
		}
		if(status == 'S') ++result;
		cout << result << endl;
	}
	return 0;
} 
