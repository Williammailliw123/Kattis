#include<bits/stdc++.h>
using namespace std;

int dp(int i,int j,string P,string s,vector<vector<int>> &rec){
    if(i == s.size() || j == P.size()) return 0;
    else if(rec[i][j] != -1) return rec[i][j];
    if(P[j] != '*'){
        if(s[i] == P[j]){
            if(i == s.size()-1 && j == P.size()-1) return rec[i][j]=1;
            else return rec[i][j]=dp(i+1,j+1,P,s,rec);
        }
        else return rec[i][j]=0;
    }
    else{
        if(j == P.size()-1) return rec[i][j]=1;
        else return rec[i][j]=max(dp(i+1,j,P,s,rec),dp(i,j+1,P,s,rec));
    }
}

int main(){
    string P;
    while(cin >> P){
        int N;
        cin >> N;
        for(int i=0 ; i<N ; ++i){
            string s;
            cin >> s;
            vector<vector<int>> rec(s.size(),vector<int>(P.size(),-1));
            int result=dp(0,0,P,s,rec);
            if(result) cout << s << endl;
        }
    }
}