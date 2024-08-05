#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<bool> ocur(n+1);
        vector<int> result;
        for(int i=0 ; i<n/2+1 ; ++i){
            int a,b;
            cin >> a >> b;
            if(!ocur[a]) ocur[a]=1;
            else result.push_back(a);
            if(!ocur[b]) ocur[b]=1;
            else result.push_back(b);
        }
        cout << min(result[0],result[1]) << ' ' << max(result[0],result[1]) << endl;
    }
}