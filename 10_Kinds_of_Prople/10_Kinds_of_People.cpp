#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    while(cin >> r >> c){
        vector<vector<char>> M;
        vector<char> t_c(c+1);
        M.resize(r+1,t_c);
        for(int i=1 ; i<=r ; ++i){
            for(int j=1 ; j<=c ; ++j) cin >> M[i][j];
        }
        int n;
        cin >> n;
        vector<vector<int>> req;
        vector<int> t_i(4);
        req.resize(n,t_i);
        for(int i=0 ; i<n ; ++i){
            int a,b,c,d;
            cin >> req[i][0] >> req[i][1] >> req[i][2] >> req[i][3];
        }
        vector<vector<pair<int,int>>> ori;
        vector<pair<int,int>> t(c+1);
        ori.resize(r+1,t);
        for(int i=1 ; i<=r ; ++i){          
            for(int j=1 ; j<=c ; ++j){
                if(!ori[i][j].first){
                    char label=M[i][j];
                    ori[i][j]=make_pair(i,j);
                    queue<pair<int,int>> Q;
                    Q.push(ori[i][j]);
                    while(!Q.empty()){
                        int a=Q.front().first,b=Q.front().second;
                        Q.pop();
                        if(a<r && !ori[a+1][b].first && M[a+1][b] == label){
                            ori[a+1][b]=make_pair(i,j);
                            Q.push(make_pair(a+1,b));
                        }
                        if(a>1 && !ori[a-1][b].first && M[a-1][b] == label){
                            ori[a-1][b]=make_pair(i,j);
                            Q.push(make_pair(a-1,b));
                        }
                        if(b<c && !ori[a][b+1].first && M[a][b+1] == label){
                            ori[a][b+1]=make_pair(i,j);
                            Q.push(make_pair(a,b+1));
                        }
                        if(b>1 && !ori[a][b-1].first && M[a][b-1] == label){
                            ori[a][b-1]=make_pair(i,j);
                            Q.push(make_pair(a,b-1));
                        }
                    }
                }
            }
        }
        
        for(int i=0 ; i<n ; ++i){
            int a=req[i][0],b=req[i][1],c=req[i][2],d=req[i][3];
            if(M[a][b] == '0' && M[c][d] == '0' && ori[a][b] == ori[c][d]) cout << "binary\n";
            else if(M[a][b] == '1' && M[c][d] == '1' && ori[a][b] == ori[c][d]) cout << "decimal\n";
            else cout << "neither\n";
        }
    }
}