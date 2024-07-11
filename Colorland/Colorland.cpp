#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	while(cin >> N){
		queue<int> B,O,P,G,R,Y;
		string s;
		for(int i=1 ; i<=N ; ++i){
			cin >> s;
			if(s == "Blue") B.push(i);
			else if(s == "Orange") O.push(i);
			else if(s == "Pink") P.push(i);
			else if(s == "Green") G.push(i);
			else if(s == "Red") R.push(i);
			else if(s == "Yellow") Y.push(i);
		}
		int loc=0,result=0;
		while(loc != N){
			while(!B.empty() && B.front()<=loc) B.pop();
			while(!O.empty() && O.front()<=loc) O.pop();
			while(!P.empty() && P.front()<=loc) P.pop();
			while(!G.empty() && G.front()<=loc) G.pop();
			while(!R.empty() && R.front()<=loc) R.pop();
			while(!Y.empty() && Y.front()<=loc) Y.pop();
			if(!B.empty()) loc=max(loc,B.front());
			if(!O.empty()) loc=max(loc,O.front());
			if(!P.empty()) loc=max(loc,P.front());
			if(!G.empty()) loc=max(loc,G.front());
			if(!R.empty()) loc=max(loc,R.front());
			if(!Y.empty()) loc=max(loc,Y.front());
			++result;
		}
		cout << result << endl;
	}
	return 0;
}
