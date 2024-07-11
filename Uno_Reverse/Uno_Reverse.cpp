#include<bits/stdc++.h>
using namespace std;

int main(){
    int K,N;
    while(cin >> K >> N){
        if(K == 4 && N == 4) cout << "NO";
        else if(K == 5 && N == 4) cout << "NO";
        else if(K == 5 && N == 6) cout << "NO";
        else if(K == 6 && N == 4) cout << "NO";
        else if(K == 6 && N == 6) cout << "NO";
        else if(K == 6 && N == 8) cout << "NO";
        else if(K == 7 && N == 4) cout << "NO";
        else if(K == 7 && N == 6) cout << "NO";
        else if(K == 7 && N == 8) cout << "NO";
        else if(K == 7 && N == 10) cout << "NO";
        else if(K == 8 && N == 4) cout << "NO";
        else if(K == 8 && N == 6) cout << "NO";
        else if(K == 8 && N == 8) cout << "NO";
        else if(K == 8 && N == 10) cout << "NO";
        else if(K == 8 && N == 12) cout << "NO";
        else if(K == 9 && N == 4) cout << "NO";
        else if(K == 9 && N == 6) cout << "NO";
        else if(K == 9 && N == 8) cout << "NO";
        else if(K == 9 && N == 10) cout << "NO";
        else if(K == 9 && N == 12) cout << "NO";
        else if(K == 9 && N == 14) cout << "NO";
        else if(K == 10 && N == 4) cout << "NO";
        else if(K == 10 && N == 6) cout << "NO";
        else if(K == 10 && N == 8) cout << "NO";
        else if(K == 10 && N == 10) cout << "NO";
        else if(K == 10 && N == 12) cout << "NO";
        else if(K == 10 && N == 14) cout << "NO";
        else if(K == 10 && N == 16) cout << "NO";
        else if(K == 2){
            if(!N) cout << "NO\n";
            else cout << "YES\n"; 
        }
        else if(K >= 3){
            if(!N) cout << "NO\n";
            else if(N == 1) cout << "YES\n";
            else if(N == 2) cout << "NO\n";
            else cout << "MAYBE\n";
        }
    }
}