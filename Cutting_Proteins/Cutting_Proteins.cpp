#include<bits/stdc++.h>
using namespace std;

int main(){
    string P;
    int K;
    while(cin >> P >> K){
        int result;
        if(!((P.size()-1)%K)) result=(P.size()-1)/K;
        else result=(P.size()-1)/K+1;
        for(int i=0 ; i<26 ; ++i){
            char c='a'+i;
            int id=0,cnt=0;
            while(id<P.size()){
                if(P[id] == c) ++id;
                else{
                    ++cnt;
                    id+=K;
                }
            }
            result=min(result,cnt);
        }
        cout << result << endl;
    }
}