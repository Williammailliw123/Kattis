#include<bits/stdc++.h>
using namespace std;

int main(){
    double n;
    while(cin >> n){
        int result=ceil(log2(n))+1;
        cout << result << endl;
    }
}