#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b;
	while(cin >> a >> b){
		long long result=0,c;
		if(a%b) result=0;
		else{
			c=a/b;
			long long mid=sqrt(c);
			if(c == mid*mid) ++result;			
			else if(!(c%mid)) result+=2;
			for(int i=1 ; i<mid ; ++i){
				if(!(c%i)) result+=2;
			}
		}
		cout << result << endl;
	}
	return 0;
}
