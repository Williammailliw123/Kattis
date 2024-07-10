#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	while(cin >> a >> b){
		if(!a) break;
		vector<int> r;
		int tmp_a=max(a,b),tmp_b=min(a,b);
		while(1){
			r.push_back(tmp_a/tmp_b);
			int tmp_c=tmp_a%tmp_b;
			tmp_a=tmp_b;
			tmp_b=tmp_c;
			if(!tmp_b) break;
		}
		bool result=0;
		for(int i=0 ; i<r.size() && r[i] == 1 ; ++i){
			if(result) result=0;
			else result=1;
		}
		if(r.size() == 1) cout << "Stan wins\n";
		else if(!result) cout << "Stan wins\n";
		else cout << "Ollie wins\n";
	}
	return 0;
}
