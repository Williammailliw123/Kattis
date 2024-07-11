#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<bool>> pic,sea;

void DFS(int a,int b){
	sea[a][b]=1;
	if(a>0 && !sea[a-1][b] && !pic[a-1][b]) DFS(a-1,b);
	if(b<M-1 && !sea[a][b+1] && !pic[a][b+1]) DFS(a,b+1);
	if(a<N-1 && !sea[a+1][b] && !pic[a+1][b]) DFS(a+1,b);
	if(b>0 && !sea[a][b-1] && !pic[a][b-1]) DFS(a,b-1);
}

int main(){
	while(cin >> N >> M){
		pic.clear();
		vector<bool> tmp(M);
		pic.resize(N,tmp);
		sea=pic;
		
		for(int i=0 ; i<N ; ++i){
			for(int j=0 ; j<M ; ++j){
				char c;
				cin >> c; 
				if(c == '0') pic[i][j]=0;
				else pic[i][j]=1;
			}
		}
		for(int i=0 ; i<M ; ++i) if(!pic[0][i] && !sea[0][i]) DFS(0,i);
		for(int i=0 ; i<M ; ++i) if(!pic[N-1][i] && !sea[N-1][i]) DFS(N-1,i);
		for(int i=0 ; i<N ; ++i) if(!pic[i][0] && !sea[i][0]) DFS(i,0);
		for(int i=0 ; i<N ; ++i) if(!pic[i][M-1] && !sea[i][M-1]) DFS(i,M-1);
		
		int result=0;
		for(int i=0 ; i<N ; ++i){
			for(int j=0 ; j<M ; ++j){
				if(pic[i][j]){
					if(!i || sea[i-1][j]) ++result;
					if(j == M-1 || sea[i][j+1]) ++result;
					if(i == N-1 || sea[i+1][j]) ++result;
					if(!j || sea[i][j-1]) ++result;
				}
			}
		}
		/*cout << endl;
		for(int i=0 ; i<N ; ++i){
			for(int j=0 ; j<M ; ++j){
				cout << sea[i][j];
			}
			cout << endl; 
		}*/
		cout << result << endl; 
	}
}
