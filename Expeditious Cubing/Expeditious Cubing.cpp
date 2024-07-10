#include <bits/stdc++.h>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	vector<float> t(4);
	float tt,result;
	while(cin >> t[0] >> t[1] >> t[2] >> t[3] >> tt){
		sort(t.begin(),t.end());
		if(t[1]+t[2]+t[3] <= tt*3) cout << "infinite\n";
		else if(t[0]+t[1]+t[2] > tt*3) cout << "impossible\n";
		else{
			result=tt*3-t[1]-t[2];
			cout << fixed << setprecision(2) << result << endl;
		}
	}
	return 0;
}
