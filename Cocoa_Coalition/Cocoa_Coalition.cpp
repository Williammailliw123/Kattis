#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n,m,a;
	while(cin >> n >> m >> a){
		if(!(a%n) || !(a%m)) cout << 1 << endl;
		else if(a<n || a<m) cout << 2 << endl;
		else{
			bool flag=0;
			for(long long int i=1 ; i<=a/m && !flag ; ++i){
				if(!((a-m*i)%(n-i))){
					//cout << a << " = " << m << " * " << i << " + " << "(" << n  << " - " << i << ") * " << (a-m*i)/(n-i) << endl;
					flag=1;
				}
			}
			for(long long int i=1 ; i<=a/n && !flag ; ++i){
				if(!((a-n*i)%(m-i))){
					//cout << a << " = " << n << " * " << i << " + " << "(" << m << " - " << i << ") * " << (a-n*i)/(m-i) << endl;
					flag=1;
				}
			}
			for(long long int i=1 ; i<=sqrt(a) && !flag ; ++i){
				long long int x,y;
				if(!(a%i)){
					x=i;
					y=a/i;
					if(x<=n&&y<=m || x<=m&&y<=n) flag=1;
				}
			}
			/*if(!flag) a=m*n-a;
			for(int i=1 ; i<=sqrt(a) && !flag ; ++i){
				long long int x,y;
				if(!(a%i)){
					x=i;
					y=a/i;
					if(x<=n&&y<=m || x<=m&&y<=n) flag=1;
				}
			}*/
			if(flag) cout << 2 << endl;
			else cout << 3 << endl;
		}
	}
}
