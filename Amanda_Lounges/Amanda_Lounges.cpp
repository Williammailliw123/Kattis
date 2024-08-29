#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<int> status(n+1,-1);
        vector<pair<int,int>> emp,full,one;
        vector<vector<int>> adj(n+1);
        for(int i=0 ; i<m ; ++i){
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(!c) emp.push_back(make_pair(a,b));
            else if(c == 1) one.push_back(make_pair(a,b));
            else full.push_back(make_pair(a,b));
        }
        for(int i=0 ; i<emp.size() ; ++i){
            int a=emp[i].first,b=emp[i].second;
            status[a]=0;
            status[b]=0;
        }
        bool imp=0;
        for(int i=0 ; i<full.size() ; ++i){
            int a=full[i].first,b=full[i].second;
            if(!status[a] || !status[b]){
                imp=1;
                break;
            }
            status[a]=1;
            status[b]=1;
        }
        if(imp){
            cout << "impossible\n";
            continue;
        }
        for(int i=1 ; i<=n ; ++i){
            if(status[i] != -1) continue;
            queue<int> Q;
            for(int j=0 ; j<adj[i].size() ; ++j){
                int nei=adj[i][j];
                if(status[nei] == -1) continue;
                if(!status[nei]) status[i]=1;
                else status[i]=0;
                Q.push(i);
                break;
            }
            while(!Q.empty()){
                int cur=Q.front(),col;
                Q.pop();
                if(!status[cur]) col=1;
                else col=0;
                for(int j=0 ; j<adj[cur].size() ; ++j){
                    int nei=adj[cur][j];
                    if(status[nei] == -1){
                        status[nei]=col;
                        Q.push(nei);
                    }
                }
            }
        }
        for(int i=0 ; i<one.size() ; ++i){
            int a=one[i].first,b=one[i].second;
            if(!status[a] && !status[b] || status[a] == 1 && status[b] == 1){
                imp=1;
                break;
            }
        }
        if(imp){
            cout << "impossible\n";
            continue;
        }
        for(int i=1 ; i<=n && !imp; ++i){
            if(status[i] == -1){
                vector<int> color(n+1,-1),white,black;
                color[i]=0;
                queue<int> Q;
                Q.push(i);
                white.push_back(i);
                while(!Q.empty()){             
                    int cur=Q.front();
                    //cout << cur << endl;
                    Q.pop();
                    int col=color[cur];
                    for(int j=0 ; j<adj[cur].size() ; ++j){
                        int nei=adj[cur][j];
                        if(color[nei] == col){
                            imp=1;
                            break;
                        }
                        if(color[nei] == -1){
                            if(!col){
                                color[nei]=1;
                                black.push_back(nei);
                            }
                            else{
                                color[nei]=0;
                                white.push_back(nei);
                            }
                            Q.push(nei);
                        }
                    }
                }
                if(white.size() < black.size()){
                    for(int j=0 ; j<white.size() ; ++j) status[white[j]]=1;
                    for(int j=0 ; j<black.size() ; ++j) status[black[j]]=0;
                }
                else{
                    for(int j=0 ; j<white.size() ; ++j) status[white[j]]=0;
                    for(int j=0 ; j<black.size() ; ++j) status[black[j]]=1;
                }
            }
        }
        if(imp){
            cout << "impossible\n";
            continue;
        }
        int result=0;
        for(int i=1 ; i<=n ; ++i) if(status[i] == 1) ++result;
        cout << result << endl;
    }
}