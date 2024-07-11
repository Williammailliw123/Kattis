#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		vector<int> s(32,-1);
		for(int i=0 ; i<n ; ++i){
			string ins;
			int id_a,id_b;
			cin >> ins;
			if(ins == "SET"){
				cin >> id_a;
				s[id_a]=1;
			}
			else if(ins == "CLEAR"){
				cin >> id_a;
				s[id_a]=0;
			}
			else if(ins == "OR"){
				cin >> id_a >> id_b;
				if(s[id_a] == 1 || s[id_b] == 1) s[id_a]=1;
				else if(s[id_a] == -1 || s[id_b] == -1) s[id_a]=-1;
				else s[id_a]=0;
			}
			else if(ins == "AND"){
				cin >> id_a >> id_b;
				if(s[id_a] == 0 || s[id_b] == 0) s[id_a]=0;
				else if(s[id_a] == -1 || s[id_b] == -1) s[id_a]=-1;
				else s[id_b]=1;
			}
		}
		for(int i=31 ; i>=0 ; --i){
			if(s[i] == -1) cout << '?';
			else cout << s[i];
		}
		cout << endl;
	}
}
