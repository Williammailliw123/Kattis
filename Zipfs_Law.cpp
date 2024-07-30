#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        map<string,int> M;
        string cur;
        while(cin >> cur){
            if(cur == "EndOfText") break;
            string letter;
            for(int i=0 ; i<cur.size() ; ++i){
                char c=cur[i];
                if(c>=65 && c<=90 || c>=97 && c<=122) letter+=tolower(c);
                else{
                    if(!letter.size()) continue;
                    if(M.find(letter) != M.end()) ++M[letter];
                    else M[letter]=1;
                    letter="";
                }
            }
            if(!letter.size()) continue;
            if(M.find(letter) != M.end()) ++M[letter];
            else M[letter]=1;
        }
        vector<string> result;
        for(map<string,int>::iterator iter=M.begin() ; iter != M.end() ; ++iter){
            if(iter->second == n) result.push_back(iter->first);
        }
        if(result.empty()){
            cout << "There is no such word.\n";
            continue;
        }
        sort(result.begin(),result.end());      
        for(int i=0 ; i<result.size() ; ++i) cout << result[i] << endl;
    }
}