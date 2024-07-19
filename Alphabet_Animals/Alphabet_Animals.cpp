#include<bits/stdc++.h>
using namespace std;

int main(){
	string pre;
	while(cin >> pre){
		int n;
		cin >> n;
		vector<string> rec(n);
		vector<int> S(26);
		for(int i=0 ; i<n ; ++i){
			cin >> rec[i];
			++S[rec[i][0]-'a'];
		}
		char head=pre[pre.size()-1];
		bool fail=1,fin=0,first=1;
		int id;
		//cout << head << endl;
		for(int i=0 ; i<n ; ++i){
			if(rec[i][0] == head){
				fail=0;
				if(first){
					id=i;
					first=0;	
				}
				if(!S[rec[i][rec[i].size()-1]-'a'] || rec[i][0] == rec[i][rec[i].size()-1] && S[rec[i][rec[i].size()-1]-'a'] == 1){
					cout << rec[i] << "!\n";
					fin=1;
					break;
				}
			}
		}
		if(fin);
		else if(fail) cout << "?\n";
		else cout << rec[id] << endl;
	}
}
