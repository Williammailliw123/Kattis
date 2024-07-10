#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		unordered_map<string , int> DOM;
		string tmp;
		int result;
		for(int i=0 ; i<n ; ++i){
			cin >> tmp;
			if(DOM.count(tmp)) ++DOM[tmp];
			else DOM[tmp]=1;
		}
		for(int i=0 ; i<n ; ++i){
			cin >> tmp;
			if(!DOM.count(tmp) || !DOM[tmp]) continue;
			else{
				--DOM[tmp];
				++result;
			}
		}
		cout << result << endl;
	}
	return 0;
}
