#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(cin >> N){
        vector<vector<pair<int,int>>> rec(N);
        for(int i=0 ; i<N ; ++i){
            int k;
            cin >> k;
            for(int j=0 ; j<k ; ++j){
                int s,n;
                cin >> s >> n;
                rec[i].push_back(make_pair(s,n));
            }
        }
        int result=0;
        for(int k=0 ; k<1024 ; ++k){
            vector<int> status(11);
            int tmp=k,id=1;
            while(tmp){
                status[id]=tmp%2;
                tmp/=2;
                ++id;
            }
            int cnt=0;
            for(int i=0 ; i<N ; ++i){
                int val=0;
                for(int j=0 ; j<rec[i].size() ; ++j){
                    int s=rec[i][j].first,n=rec[i][j].second;
                    if(status[abs(s)] == 0 && s<0) val+=n;
                    else if(status[abs(s)] == 0 && s>0) val-=n;
                    else if(status[abs(s)] == 1 && s<0) val-=n;
                    else val+=n;
                }
                if(val>0) cnt+=val;
            }
            result=max(result,cnt);
        }
        cout << result << endl;
    }
}