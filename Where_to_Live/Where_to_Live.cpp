#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		vector<int> x(n),y(n);
		int x_sum=0,y_sum=0;
		for(int i=0 ; i<n ; ++i){
			cin >> x[i] >> y[i];
			x_sum+=x[i];
			y_sum+=y[i];
		}
		int x_result,y_result,x1,x2,y1,y2;
		if(!(x_sum%n)) x_result=x_sum/n;
		else{
			x1=x_sum/n;
			x2=x_sum/n+1;
			int tmp1=0,tmp2=0;
			for(int i=0 ; i<n ; ++i){
				tmp1+=(x1-x[i])*(x1-x[i]);
				tmp2+=(x2-x[i])*(x2-x[i]);
			}
			if(tmp1<=tmp2) x_result=x1;
			else x_result=x2;
		}
		if(!(y_sum%n)) y_result=y_sum/n;
		else{
			y1=y_sum/n;
			y2=y_sum/n+1;
			int tmp1=0,tmp2=0;
			for(int i=0 ; i<n ; ++i){
				tmp1+=(y1-y[i])*(y1-y[i]);
				tmp2+=(y2-y[i])*(y2-y[i]);
			}
			if(tmp1<=tmp2) y_result=y1;
			else y_result=y2;
		}
		cout << x_result << " " << y_result << endl; 
	}
}
