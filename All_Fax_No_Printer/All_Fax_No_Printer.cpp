#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,k;
    while(cin >> n >> k){
        vector<pair<int,int>> data(n);
        for(int i=0 ; i<n ; ++i){
            int a,b;
            cin >> a >> b;
            data[i]=make_pair(a,b);
        }
        vector<int> best(n);
        priority_queue<int,vector<int>,greater<int>> small;
        priority_queue<int> big;
        map<int,int> del;
        int cnt=0;
        for(int i=0 ; i<n ; ++i){
            if(i) best[i]=best[i-1];
            int start=data[i].first,finish=data[i].first+data[i].second;
            while(!small.empty()){
                if(del.find(small.top()) != del.end()){
                    --del[small.top()];
                    if(!del[small.top()]) del.erase(small.top());
                    small.pop();
                }
                else if(small.top()<=start){
                    small.pop();
                    ++cnt;
                }
                else break;
            }
            if(i-cnt<k){
                small.push(finish);
                big.push(finish);
            }
            else{
                ++best[i];
                ++cnt;
                small.push(finish);
                big.push(finish);
                int x=big.top();
                big.pop();
                if(del.find(x) == del.end()) del[x]=1;
                else ++del[x];
            }
        }

        vector<int> orig(n);
        priority_queue<int,vector<int>,greater<int>> sml;
        for(int i=0 ; i<n ; ++i){
            if(i) orig[i]=orig[i-1];
            int start=data[i].first,finish=data[i].first+data[i].second;
            while(!sml.empty() && sml.top()<=start) sml.pop();
            if(sml.size()<k) sml.push(finish);
            else ++orig[i];
        }
        //for(int i=0 ; i<n ; ++i) cout << best[i] << endl;
        for(int i=0 ; i<n ; ++i) cout << orig[i]-best[i] << endl;
    }
}