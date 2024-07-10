#include<bits/stdc++.h>
using namespace std;

int result;
vector<char> solve(vector<char> SS){
	bool j=0;
	while(!j){
		while(SS[SS.size()-1] == 'P') SS.pop_back();
		j=1;
		for(int i=SS.size()-1 ; i>=2 ; --i){
			if(SS[i] == 'C' && SS[i-2] == 'P'){
				SS[i]='P';
				SS[i-2]='C';
				++result;
				j=0;
			}
		}
	}
	return SS;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin >> s){
		result=0;
		vector<char> SS(s.begin(),s.end());
		SS=solve(SS);
		while(SS[SS.size()-2] == 'P'){
			SS.pop_back();
			SS[SS.size()-1]='C';
			++result;
			SS=solve(SS);
		}
		cout << result << endl;
	}
	return 0;
} 
