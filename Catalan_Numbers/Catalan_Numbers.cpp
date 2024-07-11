#include<bits/stdc++.h>
#define digit 3005
using namespace std;

int q;
vector<vector<int>> catalan;

void mult(int id,int n){
    for(int i=0 ; i<digit ; ++i){
    	catalan[id][i]=catalan[id-1][i]*n;
	}
	for(int i=0 ; i<digit-1 ; ++i){
		catalan[id][i+1]+=catalan[id][i]/10;
		catalan[id][i]%=10;
	}
}

void division(int id,int n){
	int r = 0;
	vector<int> quo(digit);
	for(int i=digit-1; i>=0; i--){
		r = r * 10 + catalan[id][i];
		quo[i] = r / n;
		r %= n;
	}	
	catalan[id]=quo;
}

void Compute(){
    for(int i=1 ; i<=5000 ; ++i){
    	mult(i,4*i-2);
    	division(i,i+1);
	}
}

int main(){
	vector<int> v(digit);
	catalan.resize(5001,v);
    vector<int> tmp(1,1);
    catalan[0]=tmp;
    Compute();
    while(cin >> q){
        for(int i=0 ; i<q ; ++i){
            int x,id=0;
            cin >> x;
            while(!catalan[x][catalan[x].size()-1-id]) ++id;
            for(int j=id ; j<catalan[x].size() ; ++j){
                cout << catalan[x][catalan[x].size()-1-j];
            }
            cout << endl;
        }
    }
}

