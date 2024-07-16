#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int result=0,cnt_a=0,cnt_b=0,cnt_c=0;
        for(int i=0 ; i<s.size() ; ++i){
            if(s[i] == 'A') ++cnt_a;
            else if(s[i] == 'B') ++cnt_b;
            else ++cnt_c;
            int tmp=max(cnt_a,max(cnt_b,cnt_c))-min(cnt_a,min(cnt_b,cnt_c));
            result=max(result,tmp);
        }
        cout << result << endl;
    }
}