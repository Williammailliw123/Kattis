#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	while(cin >> N >> M){
		map<pair<int,int>,int> rec;
		pair<int,int> p;
		for(int i=1 ; i<=M ; ++i){
			int a,b;
			cin >> a >> b;
			if(N == 2){
				p=make_pair(a,b);
				rec[p]=i;
				p=make_pair(b,a);
			}
			else if(a == 1 && b == N || a == N && b == 1) p=make_pair(max(a,b),min(a,b));
			else p=make_pair(min(a,b),max(a,b));
			rec[p]=i;
		}
		vector<int> result;
		bool imp=0;
		for(int i=1 ; i<N ; ++i){
			if(imp) break;
			p=make_pair(i,i+1);
			if(rec.find(p) == rec.end()) imp=1;
			else result.push_back(rec[p]);
		}
		p=make_pair(N,1);
		if(rec.find(p) == rec.end()) imp=1;
		else result.push_back(rec[p]);
		if(imp) cout << "impossible\n";
		else{
			for(int i=0 ; i<N ; ++i) cout << result[i] << endl;
		}
	}
}
