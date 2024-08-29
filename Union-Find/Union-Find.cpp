#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N,Q;
    while(cin >> N >> Q){
        vector<int> label(N);
        vector<vector<int>> gr_member(N);
        for(int i=0 ; i<N ; ++i){
            label[i]=i;
            gr_member[i].push_back(i);
        }
        for(int i=0 ; i<Q ; ++i){
            char ins;
            int a,b;
            cin >> ins >> a >> b;
            if(ins == '?'){
                if(label[a] == label[b]) cout << "yes\n";
                else cout << "no\n";
            }
            else if(ins == '='){
                int la=label[a],lb=label[b];
                if(la == lb) continue;
                else if(gr_member[la].size() < gr_member[lb].size()){
                    for(int j=0 ; j<gr_member[la].size() ; ++j){
                        label[gr_member[la][j]]=lb;
                        gr_member[lb].push_back(gr_member[la][j]);
                    }
                }
                else{               
                    for(int j=0 ; j<gr_member[lb].size() ; ++j){
                        label[gr_member[lb][j]]=la;
                        gr_member[la].push_back(gr_member[lb][j]);
                    }
                }
            }
        }
    }
}