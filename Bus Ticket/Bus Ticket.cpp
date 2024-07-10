#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

long long s,p,m,n;
vector<long long> trip,next_buy,record;

long long low_cost(int cur){
	if(record[cur]) return record[cur];
	if(cur == n-1) return record[cur]=min(s,p);
	else{
		if(next_buy[cur] == INF) return record[cur]=min(low_cost(cur+1)+s,p);
		else return record[cur]=min(low_cost(cur+1)+s,low_cost(next_buy[cur])+p);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> s >> p >> m >> n){
		trip.clear();
		trip.resize(n);
		next_buy.clear();
		next_buy.resize(n);
		record.clear();
		record.resize(n);
		queue<pair<long long,long long>> q;
		int tmp;
		for(int i=0 ; i<n ; ++i){
			cin >> tmp;
			while(!q.empty() && tmp>q.front().second){
				next_buy[q.front().first]=i;
				q.pop();
			}
			trip[i]=tmp;
			q.push(make_pair(i,tmp+m-1));
		}
		while(!q.empty()){
			next_buy[q.front().first]=INF;
			q.pop();
		}
		long long result=low_cost(0);
		cout << result << endl;
	}
	return 0;
}
