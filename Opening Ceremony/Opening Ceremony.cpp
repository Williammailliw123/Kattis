#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin.tie(0), ios::sync_with_stdio(0);
	while(cin >> n){
		int result=0;
		vector<int> data;
		int tmp;
		for(int i=0 ; i<n ; ++i){
			cin >> tmp;
			data.push_back(tmp);
		}
		sort(data.begin(),data.end());
		while(1){
			if(data.empty()) break;
			else if(data[data.size()-1] >= data.size()){
				++result;
				data.pop_back();
			}
			else break;
		}
		int cur_size=data.size(),cur_num=0,i=0;
		while(i<data.size()){			
			cur_num=data[i];
			++i;
			--cur_size;
			while(1){
				if(data.empty()) break;
				else if(data[data.size()-1]-cur_num >= cur_size){
					++result;
					--cur_size;
					data.pop_back();
				}
				else break;
			}			
		}
		result += cur_size+cur_num;
		cout << result << endl;
	}
	return 0;
}
