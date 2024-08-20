#include<bits/stdc++.h>
using namespace std;

bool check(string s,int id,int sum){
    for(int i=id ; i<s.size() ; ++i){
        if(s[i] == '9') sum-=9;
        else if(sum == s[i]-48) return 1;
        else return 0;
    }
    return 1;
}

int main(){
    string s;
    while(cin >> s){
        int sum=0;
        for(int i=0 ; i<s.size() ; ++i) sum+=s[i]-48;
        bool init=check(s,0,sum);
        bool bigger=0;
        if(init){
            cout << '1';
            sum-=1;
            bigger=1;
        }
        for(int i=0 ; i<s.size() ; ++i){
            if(!bigger){
                int cur=s[i]-48;
                bool flag=check(s,i+1,sum-cur);            
                if(flag){
                    cout << cur+1;
                    sum-=cur+1;
                    bigger=1;
                }
                else{
                    cout << cur;
                    sum-=cur;
                }
            }
            else{
                int num=s.size()-i;
                if(9*(num-1) >= sum) cout << '0';
                else{
                    cout << sum-9*(num-1);
                    sum-=sum-9*(num-1);
                }
            }
        }
        cout << endl;
    }
}