#include<bits/stdc++.h>
using namespace std;

int main(){
    string ans="0";
    while(1){
        cout << ans << endl;
        string tmp1,tmp2,status;
        char c;
        int delay;
        cin >> tmp1 >> status;
        if(status == "GRANTED") break;
        cin >> c >> delay >> tmp2;
        if(delay == 5) ans.push_back('0');
        else{
            int cur=(delay-14)/9;
            if(ans[cur] == 57) ans[cur]=65;
            else if(ans[cur] == 90) ans[cur]=97;
            else ++ans[cur]; 
        }
    }
}