#include<bits/stdc++.h>
using namespace std;

int t;
vector<vector<int>> T;
vector<int> discover,ex,root,num;

int DFS(int n){
	int child=1;
	discover[n]=t;
	t++;
	if(T[n].empty()){
		ex[n]=t;
		t++;
		num[n]=1;
		return 1;
	}
	else{
		for(int i=0 ; i<T[n].size() ; ++i) child+=DFS(T[n][i]);
		ex[n]=t;
		t++;
		num[n]=child;
		return child;
	}
}

int main(){
	int N;
	while(cin >> N){
		t=0;
		T.clear();
		T.resize(N+1);
		discover.clear();
		discover.resize(N+1);
		ex.clear();
		ex.resize(N+1);
		root.clear();
		root.resize(N+1);
		num.clear();
		num.resize(N+1);
		for(int i=1 ; i<N+1 ; ++i){
			int pa;
			cin >> pa;
			if(!pa) root.push_back(i);
			else T[pa].push_back(i);
		}
		
		for(int i=0 ; i<root.size() ; ++i) num[root[i]]=DFS(root[i]);
		//for(int i=1 ; i<N+1 ; ++i) cout << "num" << i << ": " <<num[i] << endl;
		int Q;
		cin >> Q;
		for(int i=0 ; i<Q ; ++i){
			int M;
			cin >> M;
			vector<int> query(M),tmp;
			for(int j=0 ; j<M ; ++j){
				int a;
				cin >> a;
				bool flag=0;
				for(int k=0 ; k<tmp.size() ; ++k){
					if(!tmp[k]) continue;
					else if(discover[a]>discover[tmp[k]] && ex[a]<ex[tmp[k]]){
						flag=1;
						break;
					}
					else if(discover[a]<discover[tmp[k]] && ex[a]>ex[tmp[k]]) tmp[k]=0;
				}
				if(!flag) tmp.push_back(a);
			}
			int result=0;
			for(int j=0 ; j<tmp.size() ; ++j){
				if(tmp[j]) result+=num[tmp[j]];
			}
			cout << result << endl;
		}
	}
} 
