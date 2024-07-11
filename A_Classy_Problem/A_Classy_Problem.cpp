#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,string> a,pair<int,string> b)
{
    return a.first > b.first || a.first == b.first && a.second < b.second;
}

int main(){
	int T;
	while(cin >> T){	
		for(int i=0 ; i<T ; ++i){
			int n;
			cin >> n;
			vector<vector<string>> record;
			vector<string> tmp(2);
			record.resize(n,tmp);
			for(int j=0 ; j<n ; ++j){
				string t;
				cin >> record[j][0] >> record[j][1] >> t;
				record[j][0].pop_back();
			}
			
			vector<pair<int,string>> z(n);
			for(int j=0 ; j<n ; ++j){
				int score=0,p=9;
				for(int k=record[j][1].length()-1 ; k >= 0 ; --k){
					if(!k){
						if(record[j][1][k] == 'u') score+=2*pow(3,p);
						else if(record[j][1][k] == 'm') score+=pow(3,p);
						--p;
						break;
					}
					else if(record[j][1][k-1] == '-'){
						if(record[j][1][k] == 'u') score+=2*pow(3,p);
						if(record[j][1][k] == 'm') score+=pow(3,p);
						--p;
					}
				}
				while(p>=0){
					score+=pow(3,p);
					--p;
				}
				z[j]=make_pair(score,record[j][0]);
			}	
			sort(z.begin(),z.end(),cmp);
			for(int j=0 ; j<n ; ++j) cout << z[j].second << endl;
			for(int j=0 ; j<30 ; ++j) cout << '=';
			cout << endl;
		}
	}
}
