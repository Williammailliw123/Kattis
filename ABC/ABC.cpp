#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    while(cin >> a >> b >> c){
        int A=min(a,min(b,c)),C=max(a,max(b,c));
        int B=a+b+c-A-C;
        for(int i=0 ; i<3 ; ++i){
            char c;
            cin >> c;
            if(c == 'A') cout << A;
            else if(c == 'B') cout << B;
            else cout << C;
            if(i == 2) cout << endl;
            else cout << " ";
        }
    }
}