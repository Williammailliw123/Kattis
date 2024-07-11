#include<bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<char>> M;
vector<vector<int>> up,down,rgt;

int find_road(int i,int j,char dir){
	if(i == 0 && j == c-1) return 1;
	if(dir == 'u' && up[i][j] != -1) return up[i][j];
	if(dir == 'd' && down[i][j] != -1) return down[i][j];
	if(dir == 'r' && rgt[i][j] != -1) return rgt[i][j];
	int result=0;
	if(i && dir != 'd' && M[i-1][j] != '#') result+=find_road(i-1,j,'u');
	if(i != r-1 && dir != 'u' && M[i+1][j] != '#') result+=find_road(i+1,j,'d');
	if(j != c-1 && M[i][j+1] != '#') result+=find_road(i,j+1,'r');
	if(dir == 'u') up[i][j]=result;
	else if(dir == 'd') down[i][j]=result;
	else if(dir == 'r') rgt[i][j]=result;
	return result; 
}

int main(){
	while(cin >> r >> c){
		if(!r && !c) break;
		vector<vector<char>> ().swap(M);
		vector<char> tmp_c(c);
		M.resize(r,tmp_c);
		for(int i=0 ; i<r ; ++i){
			for(int j=0 ; j<c ; ++j) cin >> M[i][j];
		}
		vector<vector<int>> ().swap(up);
		vector<vector<int>> ().swap(down);
		vector<vector<int>> ().swap(rgt);
		vector<int> tmp_n(c,-1);
		up.resize(r,tmp_n);
		down.resize(r,tmp_n);
		rgt.resize(r,tmp_n);
		int result=find_road(r-1,0,'r');
		cout << result << endl;
	}
}
