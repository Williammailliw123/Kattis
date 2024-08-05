#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        if(!(n%3)){
            if(n/3*2+2 > m) cout << "Arnar\n";
            else cout << "Unnar\n";
        }
        else if(n%3 == 1){
            if((n-1)/3*2+2 > m) cout << "Arnar\n";
            else cout << "Unnar\n";
        }
        else{
            if((n-2)/3*2+3 > m) cout << "Arnar\n";
            else cout << "Unnar\n";
        }
    }
}