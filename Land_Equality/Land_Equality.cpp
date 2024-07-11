#include<bits/stdc++.h>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.precision(0);
	int r,c;
	while(cin >> r >> c){
		int zero=0,one=0,two=0,start,end;
		for(int i=0 ; i<r*c ; ++i){
			int tmp;
			cin >> tmp;
			if(!i) start=tmp;
			else if(i == r*c-1) end=tmp;
			if(!tmp) ++zero;
			else if(tmp == 1) ++one;
			else ++two;
		}
		if(zero>=2) cout << 0 << endl;
		else if(zero == 1){
			if(r == 1 || c == 1){
				if(start == 1 || end == 1) cout << 1 << endl;
				else cout << 2 << endl;
			}
			else{
				if(one) cout << 1 << endl;
				else cout << 2 << endl;
			}	
		}
		else{
			if(!(two%2)) cout << 0 << endl;
			else cout << pow(2,(two-1)/2) << endl;
		}
	}
}
