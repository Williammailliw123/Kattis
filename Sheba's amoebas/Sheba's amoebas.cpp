#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void find(vector<vector<char>> &p , int r , int c){
	if(p[r-1][c-1] == '#'){
		p[r-1][c-1] = '.';
		find(p , r-1 , c-1);
		return;
	}
	else if(p[r-1][c] == '#'){
		p[r-1][c] = '.';
		find(p , r-1 , c);
		return; 
	}
	else if(p[r-1][c+1] == '#'){
		p[r-1][c+1] = '.';
		find(p , r-1 , c+1);
		return;
	}
	else if(p[r][c-1] == '#'){
		p[r][c-1] = '.';
		find(p , r , c-1);
		return; 
	}
	else if(p[r][c] == '#'){
		p[r][c] = '.';
		find(p , r , c);
		return; 
	}
	else if(p[r][c+1] == '#'){
		p[r][c+1] = '.';
		find(p , r , c+1);
		return; 
	}
	else if(p[r+1][c-1] == '#'){
		p[r+1][c-1] = '.';
		find(p , r+1 , c-1);
		return; 
	}
	else if(p[r+1][c] == '#'){
		p[r+1][c] = '.';
		find(p , r+1 , c);
		return; 
	}
	else if(p[r+1][c+1] == '#'){
		p[r+1][c+1] = '.';
		find(p , r+1 , c+1);
		return; 
	}
}

int main(){
	int m,n;
	while(cin >> m >> n){
		vector<vector<char>> p;
		vector<char> tmp(n+2);
		p.resize(m+2 , tmp);
		for(int i=0 ; i<m ; ++i){
			for(int j=0 ; j<n ; ++j) cin >> p[i+1][j+1];
		}
		int result = 0;
		for(int i=0 ; i<m ; ++i){
			for(int j=0 ; j<n ; ++j){
				if(p[i+1][j+1] == '#'){
					p[i+1][j+1] = '.';
					++result;
					find(p,i+1,j+1);
				} 				
			}
		}
		cout << result << endl << endl;
	}
	return 0;
} 
