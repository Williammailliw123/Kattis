#include<bits/stdc++.h>
using namespace std;

vector<char> D;
vector<char> status;
bool L_exit;
long long result;

long long calculate(int cur,vector<char> st){
	for(int i=cur ; i<st.size() ; ++i){
		if(st[i] == 'x'){
			if(i-2>=0 && i+2<st.size() && (st[i-1]=='v' && st[i-2]=='v' && st[i+1]=='c' && st[i+2]=='c'
			|| st[i-1]=='c' && st[i-2]=='c' && st[i+1]=='v' && st[i+2]=='v')) return 0;
			else if(i-2>=0 && st[i-1]=='v' && st[i-2]=='v' || i+2<st.size() && st[i+1]=='v' && st[i+2]=='v'
			|| i-1>=0 && i+1<st.size() && st[i-1]=='v' && st[i+1]=='v'){
				vector<char> tmp(st.begin(),st.end());
				tmp[i]='c';
				return calculate(i+1,tmp)*21;
			}
			else if(i-2>=0 && st[i-1]=='c' && st[i-2]=='c' || i+2<st.size() && st[i+1]=='c' && st[i+2]=='c'
			|| i-1>=0 && cur+1<st.size() && st[i-1]=='c' && st[i+1]=='c'){
				vector<char> tmp(st.begin(),st.end());
				tmp[i]='v';
				return calculate(i+1,tmp)*5;
			}
			else{
				vector<char> tmp1(st.begin(),st.end()),tmp2(st.begin(),st.end());
				tmp1[i]='v';
				tmp2[i]='c';
				return calculate(i+1,tmp1)*5 + calculate(i+1,tmp2)*21;
			}
		}
	}
	return 1;
}

long long sub(int cur,vector<char> st){
	for(int i=cur ; i<st.size() ; ++i){
		if(st[i] == 'x'){
			if(i-2>=0 && i+2<st.size() && (st[i-1]=='v' && st[i-2]=='v' && st[i+1]=='c' && st[i+2]=='c'
			|| st[i-1]=='c' && st[i-2]=='c' && st[i+1]=='v' && st[i+2]=='v')) return 0;
			else if(i-2>=0 && st[i-1]=='v' && st[i-2]=='v' || i+2<st.size() && st[i+1]=='v' && st[i+2]=='v'
			|| i-1>=0 && i+1<st.size() && st[i-1]=='v' && st[i+1]=='v'){
				vector<char> tmp(st.begin(),st.end());
				tmp[i]='c';
				return sub(i+1,tmp)*20;
			}
			else if(i-2>=0 && st[i-1]=='c' && st[i-2]=='c' || i+2<st.size() && st[i+1]=='c' && st[i+2]=='c'
			|| i-1>=0 && cur+1<st.size() && st[i-1]=='c' && st[i+1]=='c'){
				vector<char> tmp(st.begin(),st.end());
				tmp[i]='v';
				return sub(i+1,tmp)*5;
			}
			else{
				vector<char> tmp1(st.begin(),st.end()),tmp2(st.begin(),st.end());
				tmp1[i]='v';
				tmp2[i]='c';
				return sub(i+1,tmp1)*5 + sub(i+1,tmp2)*20;
			}
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin >> s){
		D.clear();
		D.assign(s.begin(),s.end());
		status.clear();
		status.resize(D.size());
		L_exit=0;
		result=0;
		for(int i=0 ; i<D.size() ; ++i){
			if(!L_exit && D[i] == 'L') L_exit=1;
			if(D[i] == '_') status[i]='x';
			else if(D[i] == 'A' || D[i] == 'E' || D[i] == 'I' || D[i] == 'O' || D[i] == 'U') status[i]='v';
			else status[i]='c';
		}
		//cout << sub(0,status) << endl;
		if(!L_exit){
			result=calculate(0,status)-sub(0,status);
		}
		else result=calculate(0,status);
		cout << result << endl;
	}
	return 0;
}
