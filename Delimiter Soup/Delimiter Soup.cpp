#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<char> data(n);
		cin.ignore();
		for(int i=0 ; i<n ; ++i) data[i]=getchar();
		bool flag=0;
		stack<char> record;
		char tmp;
		int i=0;
		for(; i<n ; ++i){
			if(data[i] == ' ') continue;
			else if(data[i] == '(' || data[i] == '[' || data[i] == '{') record.push(data[i]);
			else if(data[i] == ')' || data[i] == ']' || data[i] == '}'){
				if(record.empty()){
					flag=1;
					break;
				}
				tmp = record.top();
				if(data[i] == ')' && tmp == '(') record.pop();
				else if(data[i] == ']' && tmp == '[') record.pop();
				else if(data[i] == '}' && tmp == '{') record.pop();
				else{
					flag=1;
					break;
				}
			}
		}
		if(flag) cout << data[i] << " " << i << endl;
		else cout << "ok so far\n";
	}
	return 0;
}
