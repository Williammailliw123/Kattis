#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,c,b;
	while(cin >> n >> c >> b){
		vector<bool> broken(n+1);
		for(int i=1 ; i<b+1 ; ++i){
			int tmp;
			cin >> tmp;
			broken[tmp]=1;
		}
		int cur;
		if(c%2){
			cout << "10";
			--c;
			cur=3;
		}
		else{
			cout << "0";
			cur=2;
		}
		bool flag=0;
		for(int i=cur ; i<n+1 ; ++i){
			if(!c || broken[i] || flag){
				flag=0;
				cout << "0";
			}
			else{
				cout << "1";
				flag=1;
				c-=2;
			}
		}
		cout << endl;
	}
}
