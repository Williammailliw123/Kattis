#include<bits/stdc++.h>
using namespace std;

struct edge{
	int from,to,w;
};

bool operator<(const edge &e1, const edge &e2){
    return e1.w > e2.w;
}

int group(vector<int> &parent, int n){
    for (; parent[n] != n; n = parent[n]) ;
    return n;
}

int mst_kruskal(int C,vector<edge> E){
    vector<int> parent(C);
    priority_queue<edge> pq;
    int remain_edges = C-1,min_cost = 0;
    for(int i = 0; i < C; i++) parent[i] = i;

    for (int i=0 ; i<C*(C-1)/2 ; ++i) pq.push(E[i]);
    while (remain_edges > 0 && !pq.empty()) {
        edge e = pq.top();
		pq.pop();
        int g1 = group(parent, e.from),g2 = group(parent, e.to);
        
        if (g1 != g2) {
            parent[g1] = g2;
            min_cost += e.w;
            remain_edges--;
        }
        
    }
    return min_cost;
}

int main(){
	int T;
	while(cin >> T){
		for(int i=0 ; i<T ; ++i){
			int M,C;
			cin >> M >> C;
			vector<edge> E(C*(C-1)/2);
			for(int j=0 ; j<C*(C-1)/2 ; ++j){
				int a,b,c;
				cin >> a >> b >> c;
				E[j]={a,b,c};
			}
			int mst_w=mst_kruskal(C,E);
			//cout << mst_w << endl;
			if(M-C >= mst_w) cout << "yes\n";
			else cout << "no\n";
		}
	}
}
