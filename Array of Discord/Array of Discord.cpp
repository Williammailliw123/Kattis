#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector<long long> D(N);
		for(int i=0 ; i<N ; ++i) cin >> D[i];
		long long a,b,c,d,e,f;
		bool flag=0;
		for(int i=1 ; i<N ; ++i){
			if(flag) break;
			if(D[i-1]){
				a=log10(D[i-1]);
				c=D[i-1]/pow(10,a);
				d=D[i-1]-c*pow(10,a);
			}
			else{
				a=0;c=0;d=0;
			}
			if(D[i]){
				b=log10(D[i]);
				e=D[i]/pow(10,b);
				f=D[i]-e*pow(10,b);
			}
			else{
				b=0;e=0;f=0;
			}
			if(a<b) continue;
			else if(!c && e == 9) continue;			
			else if(c == 1 && e == 9){
				if(d <= f && a) continue;
				if(!a) D[i]=0;
				else D[i-1]=9*pow(10,a)+d;
			}
			else if(e == 9) D[i]=pow(10,a)+f;
			else D[i-1]=9*pow(10,a)+d;
			flag=1;
		}
		if(!flag) cout << "impossible";
		else for(int i=0 ; i<N ; ++i) cout << D[i] << " ";
		cout << endl;
	}
	return 0;
} 
