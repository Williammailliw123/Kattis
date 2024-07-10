#include<bits/stdc++.h>
#define INF 0X3f3f3f3f
using namespace std;

int F(string s,set<string> gr,vector<int> cost){
	if(gr.find(s) != gr.end()) return 0;
	int result=INF;
	for(int i=0 ; i<s.size()-1 ; ++i){
		string front,tail;
		front.assign(s.begin(),s.begin()+i+1);
		tail.assign(s.begin()+i+1,s.end());
		//cout << front << endl; 
		int fr_val;
		if(gr.find(front) != gr.end()) fr_val=0;
		else fr_val=cost[i+1];
		set<string> tmp=gr;
		tmp.insert(front);
		result=min(result,fr_val+F(tail,tmp,cost));
	}
	result=min(result,cost[s.size()]);
	return result;
}


int main(){
	string s;
	while(cin >> s){
		vector<int> cost(s.size()+1);
		for(int i=1 ; i<s.size()+1 ; ++i) cin >> cost[i];
		set<string> gr;
		int result=F(s,gr,cost);
		cout << result << endl; 
	}
}
