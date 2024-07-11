#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){
	int T;
	while(cin >> T){
		for(int i=0 ; i<T ; ++i){
			int num;
			string str;
			cin >> str;
			num=stoi(str);
			if(num == 1) cout << "IMPOSSIBLE\n";
			else if(num%2) cout << str << " = " << num/2 << " + " << num/2+1 << endl;
			else{
				int s=sqrt(num),fac=0,sum_num=INF;
				for(int i=2 ; i<=s ; ++i){
					if(!(num%i)){
						if(!(i%2) && !((num/i)%2)) continue;
						else{
							if(i%2 && i<sum_num){
								sum_num=i;
								fac=i;
							}
							else if(!(i%2) && min(i*2,num/i)<sum_num){
								sum_num=min(i*2,num/i);
								fac=i;
							}
						}
					}
				}
				//cout << "fac: " << fac << endl; 
				if(!fac) cout << "IMPOSSIBLE\n";
				else{
					int odd,even;
					if(!(fac%2)){
						even=fac;
						odd=num/fac;
					}
					else{
						even=num/fac;
						odd=fac;
					}
					cout << str << " =";
					if(2*even > odd){
						for(int j=even-odd/2 ; j<=even+odd/2 ; ++j){
							if(j == even+odd/2) cout << " " << j << endl;
							else cout << " " << j << " +";
						}
					}
					else{
						for(int j=odd/2-even+1 ; j<=odd/2+even ; ++j){
							if(j == odd/2+even) cout << " " << j << endl;
							else cout << " " << j << " +";
						}						
					}
				}
			}
		}
	}
}
