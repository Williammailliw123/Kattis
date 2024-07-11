#include<bits/stdc++.h>
using namespace std;

struct line{
	int u,t,p,d;
	line(int a,int b,int c,int e){
		u=a;t=b;p=c;d=e;
	}
};
typedef pair<int, int> pi;

int n,m,s,result=-1;
vector<vector<line>> route;

void dikjstra_route(){
	priority_queue<pi> P;
	vector<bool> flag(n);
	P.push(make_pair(s,n-1));
	while(!P.empty()){		
		int cur_t=P.top().first;
		int cur_id=P.top().second;
		if(!cur_id){
			result=cur_t;
			break;
		}
		P.pop();
		if(flag[cur_id]) continue;
		flag[cur_id]=1;
		for(int i=0 ; i<route[cur_id].size() ; ++i){
			int u=route[cur_id][i].u,t=route[cur_id][i].t,p=route[cur_id][i].p,d=route[cur_id][i].d;
			if(t+d>cur_t) continue;
			int tmp=(cur_t-t-d)%p;
			P.push(make_pair(cur_t-tmp-d,u));
		}
	}
}

int main(){	
	while(cin >> n >> m >> s){
		route.resize(n);
		int u,v,t,p,d;
		for(int i=0 ; i<m ; ++i){			
			cin >> u >> v >> t >> p >> d;			
			route[v].push_back(line(u,t,p,d));			
		}		
		dikjstra_route();
		if(result<0) cout << "impossible\n";
		else cout << result << endl;
	}
	return 0;
}
