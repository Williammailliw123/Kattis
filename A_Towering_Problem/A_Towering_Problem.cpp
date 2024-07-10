#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> r(6);
	int a,b;
	while(cin >> r[0] >> r[1] >> r[2] >> r[3] >> r[4] >> r[5] >> a >> b){
		bool flag=0;
		for(int i=0 ; i<4&&!flag ; ++i){
			for(int j=i+1 ; j<5&&!flag ; ++j){
				for(int k=j+1 ; k<6&&!flag ; ++k){
					if(r[i]+r[j]+r[k] == a){
						flag=1;
						vector<int> tmp1,tmp2;
						for(int z=0 ; z<6 ; ++z){
							if(z==i || z==j || z==k) tmp1.push_back(r[z]);
							else tmp2.push_back(r[z]);
						}
						sort(tmp1.begin(),tmp1.end(),greater<int>());
						sort(tmp2.begin(),tmp2.end(),greater<int>());
						cout << tmp1[0] << " " << tmp1[1] << " " << tmp1[2] << " " << tmp2[0] << " " << tmp2[1] << " " << tmp2[2] << endl;
					}
				}
			}
		}
	}
} 
