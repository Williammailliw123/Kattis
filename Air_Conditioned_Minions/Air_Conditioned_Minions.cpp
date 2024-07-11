#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<int> tmp(2);
		vector<vector<int>> z;
		z.resize(N,tmp);
		for(int i=0 ; i<N ; ++i){
			cin >> z[i][0] >> z[i][1];
		}
		sort(z.begin(),z.end());
		
		int cnt=1,L=z[0][0],R=z[0][1];
		for(int i=1 ; i<N ; ++i){
			if(z[i][0] <= R){
				L=z[i][0];
				R=min(z[i][1],R);
			}
			else{
				cnt++;
				L=z[i][0];
				R=z[i][1];
			}
		}
		cout << cnt << endl;
	}
}
