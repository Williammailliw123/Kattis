#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	while(cin >> n >> m >> k){
		vector<int> vis(n+1);
		vector<vector<int>> adj(n+1);
		vector<int> near(n+1);
		vector<bool> anime(n+1);
		vector<int> result(n+1,-1);
		vector<int> temp;
		for(int i=0 ; i<k ; ++i){
			int a;
			cin >> a;
			anime[a]=1;
			temp.push_back(a);
			near[a]=a;
		}
		for(int i=0 ; i<m ; ++i){
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int dist=1;
		while(!temp.empty()){
			vector<int> next;
			for(int i=0 ; i<temp.size() ; ++i){
				int cur=temp[i];
				for(int j=0 ; j<adj[cur].size() ; ++j){
					int nei=adj[cur][j];
					if(anime[nei]){
						if(near[cur] != nei){
							if(result[nei] == -1) result[nei]=dist;
							else result[nei]=min(result[nei],dist);
						}
					}
					else if(!vis[nei]){
						vis[nei]=1;
						result[nei]=dist;
						near[nei]=near[cur];
						next.push_back(nei);
					}
					else if(near[cur] != near[nei]){
						int ani_one=near[cur],ani_two=near[nei];
						if(anime[cur]){
							if(result[ani_one] == -1) result[ani_one]=2;
							else result[ani_one]=min(result[ani_one],2);
							if(result[ani_two] == -1) result[ani_two]=2;
							else result[ani_two]=min(result[ani_two],2);
						}
						else{
							if(result[ani_one] == -1) result[ani_one]=result[cur]+result[nei]+1;
							else result[ani_one]=min(result[ani_one],result[cur]+result[nei]+1);
							if(result[ani_two] == -1) result[ani_two]=result[cur]+result[nei]+1;
							else result[ani_two]=min(result[ani_two],result[cur]+result[nei]+1);	
						}					
					}
				}
			}
			++dist;
			temp=next;
		}
		for(int i=1 ; i<=n ; ++i){
			if(i == n) cout << result[i] << endl;
			else cout << result[i] << " ";
		}
	}
}
