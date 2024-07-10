#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n){
		for(int i=0 ; i<n ; ++i){
			string s;
			cin >> s;
			vector<char> D(s.begin(),s.end());
			int len=D.size();
			if(D[0] == D[D.size()-1]) ++len;
			if(len%2) cout << "Chikapu\n";
			else cout << "Bash\n";
		} 
	}
	return 0;
}
