#include<bits/stdc++.h>
using namespace std;

int main(){
	int m,a,b,c;
	while(cin >> m >> a >> b >> c){
		int big,mid,small;
		big=max(a,max(b,c));
		small=min(a,min(b,c));
		mid=a+b+c-big-small;
		if(2*m>=small+mid+big) cout << "possible\n";
		else cout << "impossible\n";
	}
}
