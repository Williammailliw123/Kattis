#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m){
		vector<vector<int>> normal_move(n+1);
		vector<int> forced_move(n+1);
		int a,b;
		for(int i=0 ; i<m ; ++i){
			cin >> a >> b;
			if(a>0) normal_move[a].push_back(b);
			else forced_move[-a]=b;
		}
		unordered_set<int> result;
		unordered_set<int> check_path;
		vector<int> record_node;
		int cur=1;
		while(1){
			if(!forced_move[cur]){
				check_path.insert(cur);
				record_node.push_back(cur);
				result.insert(cur);
				break;
			}
			else if(!check_path.count(cur)){
				check_path.insert(cur);
				record_node.push_back(cur);
				cur=forced_move[cur];
			}
			else break;
		}
		for(int i=0 ; i<record_node.size() ; ++i){
			for(int j=0 ; j<normal_move[record_node[i]].size() ; ++j){
				cur=normal_move[record_node[i]][j];
				while(1){
					if(!forced_move[cur]){
						if(!result.count(cur)) result.insert(cur);
						break;
					}
					else if(!check_path.count(cur)){
						check_path.insert(cur);
						cur=forced_move[cur];
					}
					else break;
				}
			}
		}
		//cout << "Forced_move: ";
		//for(int i=1 ; i<n+1 ; ++i) cout << forced_move[i] << " ";
		//cout << endl;
		//for(int i=0 ; i<record_node.size() ; ++i) cout << "Record_node: " << record_node[i] << " ";
		//cout << endl;
		//for(int i=0 ; i<normal_move[1].size() ; ++i) cout << normal_move[1][i] << " ";
		//cout << endl;
		cout << result.size() << endl;
	}
	return 0;
}
