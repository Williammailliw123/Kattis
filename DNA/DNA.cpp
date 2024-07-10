#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		vector<char> D(n);
		for(int i=0 ; i<n ; ++i) cin >> D[i];
		int result=0,rev=0;
		while(!D.empty()){
			while(!D.empty() && 
			(D[D.size()-1] == 'A' && rev%2 == 0 || D[D.size()-1] == 'B' && rev%2 == 1)) D.pop_back();
			if(!D.empty()){
				if(D.size() == 1){
					++result;
					break;
				}
				else if(D[D.size()-1] != D[D.size()-2]){
					D.pop_back();
					++result;
				}
				else{
					++rev;
					++result;
				}
			}			
		}
		cout << result << endl;
	}
	return 0;
}
