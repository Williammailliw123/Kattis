#include<bits/stdc++.h>
using namespace std;

int main(){
	long long aa,bb;
	int a,b,c;
	char op;
	while(cin >> aa >> op >> bb){
		if(op == '+'){
			a=aa%10000;
			b=bb%10000;
			c=(a+b)%10000;
			cout << c << endl;
		}
		else if(op == '*'){
			a=aa%10000;
			b=bb%10000;
			c=(a*b)%10000;
			cout << c << endl;
		}
		else{
			if(!bb) c=1;
			else{
				long long ll=0,t=bb;
				while(t>=2){
					++ll;
					t/=2;
				}
				vector<long long> D(ll+1),two(ll+1);
				D[0]=aa;
				D[0]=D[0]%10000;
				two[0]=1;
				for(int i=1 ; i<ll+1 ; ++i){					
					D[i]=D[i-1]*D[i-1];
					D[i]=D[i]%10000;
					//cout << D[i] << " ";
					two[i]=two[i-1]*2;
				}
				c=1;
				long long tmp=bb;
				for(int i=ll ; i>=0 ; --i){
					if(tmp<two[i]) continue;
					else if(tmp == two[i]){
						c*=D[i];
						c=c%10000;
						break;
					}
					else if(tmp > two[i]){
						tmp-=two[i];
						c*=D[i];
						c=c%10000;
					}
				}
			}			
			cout << c << endl;
		}
	}
	return 0;
} 
