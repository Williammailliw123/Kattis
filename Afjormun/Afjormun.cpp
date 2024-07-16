#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        for(int i=0 ; i<n ; ++i){
            string s;
            bool init=1;
            while(1){
                cin >> s;
                for(int i=0 ; i<s.size() ; ++i) s[i]=tolower(s[i]);
                if(init){
                    s[0]=toupper(s[0]);
                    init=0;
                }
                if(s[s.size()-1] == '.'){
                    cout << s << endl;
                    break;
                }
                else cout << s << " ";
            }
        }
    }
}