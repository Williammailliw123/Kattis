#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<char> t_value(n);
		for(int i=0 ; i<n ; ++i) cin >> t_value[i];
		cin.ignore();
		vector<char> circuit;
		char tmp;
		while((tmp=getchar()) != '\n') circuit.push_back(tmp);
		for(int i=0 ; i<circuit.size() ; ++i){
			if(circuit[i]>64 && circuit[i]<91) circuit[i]=t_value[circuit[i]-65];
		}
		stack<char> result;
		char tmp1,tmp2;
		for(int i=0 ; i<circuit.size() ; ++i){
			if(circuit[i] == 'T' || circuit[i] == 'F') result.push(circuit[i]);
			else if(circuit[i] == '-'){
				if(result.top() == 'T') result.top()='F';
				else result.top()='T';
			}
			else if(circuit[i] == '*'){
				tmp1=result.top();
				result.pop();
				tmp2=result.top();
				result.pop();
				if(tmp1 == 'T' && tmp2 == 'T') result.push('T');
				else result.push('F');
			}
			else if(circuit[i] == '+'){
				tmp1=result.top();
				result.pop();
				tmp2=result.top();
				result.pop();
				if(tmp1 == 'F' && tmp2 == 'F') result.push('F');
				else result.push('T');
			}
		}
		cout << result.top() << endl;
	}
	return 0;
}
