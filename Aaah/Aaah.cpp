#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    while(cin >> a >> b){
        if(a.size() < b.size()) cout << "no\n";
        else cout << "go\n";
    }
}