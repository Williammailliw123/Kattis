#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int N,Q;
	while(cin >> N >> Q){
		vector<long long> arr(N+1);
		for(int i=0 ; i<Q ; ++i){
			char op;
			cin >> op;
			if(op == '+'){
				long long id,value;
				cin >> id >> value;
				++id;
				for(; id<=N ; id+=id&(-id)) arr[id]+=value;
			}
			else{
				long long id,result=0;
				cin >> id;
				for(; id>0 ; id-=id&(-id)){
					if(!arr[id]) continue;
					result+=arr[id];
				}
				cout << result << "\n";
			}
		}
	}
	return 0;
} 
