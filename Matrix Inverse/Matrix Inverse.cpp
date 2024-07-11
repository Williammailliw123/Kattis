#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b,c,d,cnt=1;
	while(cin >> a >> b >> c >> d){
		int tmp=a*d-b*c;
		cout << "Case " << cnt << ":\n" << d/tmp << " " << -(b/tmp) << "\n" << -(c/tmp) << " " << a/tmp << "\n";
		++cnt;
	}
	return 0;
}
