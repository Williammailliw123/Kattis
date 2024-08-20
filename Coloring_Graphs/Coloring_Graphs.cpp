#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;

bool draw(vector<bool> used,vector<int> color_map,int cur,int k){
    vector<bool> nei_color(k);
    for(int i=0 ; i<adj[cur].size() ; ++i) if(color_map[adj[cur][i]] != -1) nei_color[color_map[adj[cur][i]]]=1;
    if(cur == N-1){
        for(int i=0 ; i<k ; ++i) if(!nei_color[i]) return 1;
        return 0;
    }
    for(int i=0 ; i<k ; ++i){
        if(used[i] && !nei_color[i]){
            vector<int> tmp_map=color_map;
            tmp_map[cur]=i;
            if(draw(used,tmp_map,cur+1,k)) return 1;
        }
    }
    for(int i=0 ; i<k ; ++i){
        if(!used[i]){
            vector<bool> tmp_used=used;
            vector<int> tmp_map=color_map;
            tmp_used[i]=1;
            tmp_map[cur]=i;
            if(draw(tmp_used,tmp_map,cur+1,k)) return 1;
            break;
        }
    }
    return 0;
}

int main(){
    while(cin >> N){
        vector<vector<int>> ().swap(adj);
        adj.resize(N);
        for(int i=0 ; i<N ; ++i){
            int num;
            while(cin >> num){
                adj[i].push_back(num);
                char c=getchar();
                if(c == '\n') break;
            }
        }
        bool success=0;
        int result=1;
        for( ; result<=N ; ++result){
            vector<bool> used(result);
            vector<int> color_map(N,-1);
            success=draw(used,color_map,0,result);
            if(success) break;
        }
        cout << result << endl;
    }
}