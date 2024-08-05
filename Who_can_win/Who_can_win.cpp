#include<bits/stdc++.h>
using namespace std;

bool eval(char a,char b,char c,char d){
    if(a == b && b == c && c == d) return 1;
    else return 0;
}

int detect_status(vector<vector<char>> M){
    if(eval(M[0][0],M[0][1],M[0][2],'X') || eval(M[1][0],M[1][1],M[1][2],'X') || eval(M[2][0],M[2][1],M[2][2],'X')
    || eval(M[0][0],M[1][0],M[2][0],'X') || eval(M[0][1],M[1][1],M[2][1],'X') || eval(M[0][2],M[1][2],M[2][2],'X')
    || eval(M[0][0],M[1][1],M[2][2],'X') || eval(M[0][2],M[1][1],M[2][0],'X')) return 1;
    else if(eval(M[0][0],M[0][1],M[0][2],'O') || eval(M[1][0],M[1][1],M[1][2],'O') || eval(M[2][0],M[2][1],M[2][2],'O')
    || eval(M[0][0],M[1][0],M[2][0],'O') || eval(M[0][1],M[1][1],M[2][1],'O') || eval(M[0][2],M[1][2],M[2][2],'O')
    || eval(M[0][0],M[1][1],M[2][2],'O') || eval(M[0][2],M[1][1],M[2][0],'O')) return 2;
    else return 0;
}

int find_who_win(vector<vector<char>> M){
    int result=detect_status(M);
    if(result) return result;
    int O_cnt=0,X_cnt=0;
    for(int i=0 ; i<3 ; ++i){
        for(int j=0 ; j<3 ; ++j){
            if(M[i][j] == 'O') ++O_cnt;
            else if(M[i][j] == 'X') ++X_cnt;
        }
    }
    char icon;
    if(O_cnt == X_cnt) icon='X';
    else icon='O';
    bool a_win=0,b_win=0;
    for(int i=0 ; i<3 ; ++i){
        for(int j=0 ; j<3 ; ++j){
            if(M[i][j] == '_'){
                vector<vector<char>> next=M;
                next[i][j]=icon;
                int x=find_who_win(next);
                if(x == 3) return 3;
                else if(x == 1) a_win=1;
                else if(x == 2) b_win=1;
                if(a_win && b_win) return 3;
            }
        }
    }
    if(a_win) return 1;
    else if(b_win) return 2;
    else return 0;
}

int main(){
    vector<vector<char>> M(3,vector<char>(3));
    for(int i=0 ; i<3 ; ++i){
        for(int j=0 ; j<3 ; ++j) cin >> M[i][j];
    }
    int result=find_who_win(M);
    if(!result) cout << "ingen kan vinna\n";
    else if(result == 1) cout << "Johan kan vinna\n";
    else if(result == 2) cout << "Abdullah kan vinna\n";
    else cout << "Abdullah och Johan kan vinna\n";
}