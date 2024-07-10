#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll T;
	while(cin >> T){
		for(ll i=0 ; i<T ; ++i){
			ll W=0,B=0,N;
			cin >> N;
			vector<pair<ll,char>> data;
			for(ll j=0 ; j<N ; ++j){
				ll num;
				char col;
				cin >> num >> col;
				if(!j || data[data.size()-1].second != col){
					data.push_back(make_pair(num,col));
				}
				else data[data.size()-1].first+=num;
				if(col == 'W') W+=num;
				else B+=num;
			}
			ll result=0,tmp_w=0,tmp_b=0,cur_id=0;
			if(!W || !B){
				result=data[0].first;
				cur_id=2;
			}
			while(1){
				//cout << "tmp_w: " << tmp_w << "tmp_b: " << tmp_b << endl;
				if(cur_id >= data.size()) break;
				if(data[cur_id].second == 'W'){
					if(tmp_b && !(W*tmp_b%B) && tmp_w*B < W*tmp_b && (tmp_w+data[cur_id].first)*B >= W*tmp_b ){
						if(data[cur_id].first == W*tmp_b/B-tmp_w){
							cur_id++;
							result++;
							tmp_w=0;
							tmp_b=0;
						}
						else{
							data[cur_id].first-=(W*tmp_b/B-tmp_w);
							result++;
							tmp_w=0;
							tmp_b=0;
						}
					}
					else{
						tmp_w+=data[cur_id].first;
						cur_id++;
					}
				}
				else{
					if(tmp_w && !(B*tmp_w%W) && tmp_b*W < B*tmp_w && (tmp_b+data[cur_id].first)*W >= B*tmp_w ){
						if(data[cur_id].first == B*tmp_w/W-tmp_b){
							cur_id++;
							result++;
							tmp_w=0;
							tmp_b=0;
						}
						else{
							data[cur_id].first-=(B*tmp_w/W-tmp_b);
							result++;
							tmp_w=0;
							tmp_b=0;
						}
					}
					else{
						tmp_b+=data[cur_id].first;
						cur_id++;
					}
				}			
			}
			cout << result << endl;
		}
	}
	
	
}
