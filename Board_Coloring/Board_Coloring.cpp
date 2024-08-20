#include<bits/stdc++.h>
using namespace std;

bool remove(vector<vector<char>> &data,int i,int j){
    bool result=1;
    if(data[i-1][j] == 'W') result=0;
    if(data[i-1][j+1] == 'W') result=0;
    if(data[i][j+1] == 'W') result=0;
    if(data[i+1][j+1] == 'W') result=0;
    if(data[i+1][j] == 'W') result=0;
    if(data[i+1][j-1] == 'W') result=0;
    if(data[i][j-1] == 'W') result=0;
    if(data[i-1][j-1] == 'W') result=0;
    if(!result) return 0;
    if(data[i][j] == 'U'){
        char col='U';
        if(data[i-1][j] != 'U') col=data[i-1][j];
        else if(data[i-1][j+1] != 'U') col=data[i-1][j+1];
        else if(data[i][j+1] != 'U') col=data[i][j+1];
        else if(data[i+1][j+1] != 'U') col=data[i+1][j+1];
        else if(data[i+1][j] != 'U') col=data[i+1][j];
        else if(data[i+1][j-1] != 'U') col=data[i+1][j-1];
        else if(data[i][j-1] != 'U') col=data[i][j-1];
        else if(data[i-1][j-1] != 'U') col=data[i-1][j-1];
        if(col == 'U') return 0;
        if(data[i-1][j] != 'U' && data[i-1][j] != col) result=0;
        if(data[i-1][j+1] != 'U' && data[i-1][j+1] != col) result=0;
        if(data[i][j+1] != 'U' && data[i][j+1] != col) result=0;
        if(data[i+1][j+1] != 'U' && data[i+1][j+1] != col) result=0;
        if(data[i+1][j] != 'U' && data[i+1][j] != col) result=0;
        if(data[i+1][j-1] != 'U' && data[i+1][j-1] != col) result=0;
        if(data[i][j-1] != 'U' && data[i][j-1] != col) result=0;
        if(data[i-1][j-1] != 'U' && data[i-1][j-1] != col) result=0;
        if(!result) return 0;
        data[i-1][j]='U';
        data[i-1][j+1]='U';
        data[i][j+1]='U';
        data[i+1][j+1]='U';
        data[i+1][j]='U';
        data[i+1][j-1]='U';
        data[i][j-1]='U';
        data[i-1][j-1]='U';
        return 1;
    }
    else{
        char col=data[i][j];
        if(data[i-1][j] != 'U' && data[i-1][j] != col) result=0;
        if(data[i-1][j+1] != 'U' && data[i-1][j+1] != col) result=0;
        if(data[i][j+1] != 'U' && data[i][j+1] != col) result=0;
        if(data[i+1][j+1] != 'U' && data[i+1][j+1] != col) result=0;
        if(data[i+1][j] != 'U' && data[i+1][j] != col) result=0;
        if(data[i+1][j-1] != 'U' && data[i+1][j-1] != col) result=0;
        if(data[i][j-1] != 'U' && data[i][j-1] != col) result=0;
        if(data[i-1][j-1] != 'U' && data[i-1][j-1] != col) result=0;
        if(!result) return 0;
        data[i][j]='U';
        data[i-1][j]='U';
        data[i-1][j+1]='U';
        data[i][j+1]='U';
        data[i+1][j+1]='U';
        data[i+1][j]='U';
        data[i+1][j-1]='U';
        data[i][j-1]='U';
        data[i-1][j-1]='U';
        return 1;
    }
}

int main(){
    int N,M;
    while(cin >> N >> M){
        vector<vector<char>> data(N,vector<char> (M));
        for(int i=0 ; i<N ; ++i){
            for(int j=0 ; j<M ; ++j) cin >> data[i][j];
        }
        bool cont=1;
        while(cont){
            cont=0;
            //cout << "pig\n";
            for(int i=1 ; i<N-1 ; ++i){
                for(int j=1 ; j<M-1 ; ++j){
                    if(data[i][j] == 'W') continue;
                    cont=cont || remove(data,i,j);
                }
            }
        }
        bool result=1;
        for(int i=0 ; i<N && result ; ++i){
            for(int j=0 ; j<M && result ; ++j){
                if(data[i][j] == 'W' || data[i][j] == 'U') continue;
                else result=0;
            }
        }
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
}