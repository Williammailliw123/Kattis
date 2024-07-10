#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,s,m;
	while(cin >> n >> s >> m){
		vector<int> z(n);
		for(int i=0 ; i<n ; ++i) cin >> z[i];
		
		int start=s-1,cnt=0;
		vector<bool> flag(n);
		while(1){
			if(z[start]==m){
				cout << "magic\n" << cnt << endl;
				break;
			}
			else{
				if(start>=n){
					cout << "right\n" << cnt << endl;
					break;
				}
				else if(start<0){
					cout << "left\n" << cnt << endl;
					break;
				}
				else if(flag[start]){
					cout << "cycle\n" << cnt << endl;
					break;
				}
				flag[start]=1;
				start+=z[start];
				++cnt;
			}
		}
	}
	
	
}
