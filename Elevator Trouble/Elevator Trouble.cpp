#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int f,s,g,u,d;
vector<bool> vis;

int F(int cur){
	if(cur == g) return 0;
	else if(cur<g && u && !((g-cur)%u)) return (g-cur)/u;
	else if(cur+u>f || cur-d<1){
		if(cur+u>f && cur-d<1) return INF;
		else if(cur-d >= 1 && !vis[cur-d]){
			vis[cur-d]=1;
			return F(cur-d)+1;
		}
		else if(cur+u<=f && !vis[cur+u]){
			vis[cur+u]=1;
			return F(cur+u)+1;
		}
		else return INF;
	}
	else{
		if(vis[cur+u] && vis[cur-d]) return INF;
		else if(vis[cur+u]){
			vis[cur-d]=1;
			return F(cur-d)+1;
		}
		else if(vis[cur-d]){
			vis[cur+u]=1;
			return F(cur+u)+1;
		}
		else{
			vis[cur+u]=1;
			vis[cur-d]=1;
			return min(F(cur+u)+1,F(cur-d)+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> f >> s >> g >> u >> d){
		vis.clear();
		vis.resize(f+1,0);
		int result=F(s);
		if(result >= INF) cout << "use the stairs\n";
		else cout << result << endl;
	}
	return 0;
} 
