#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstring>
#include <string>
using namespace std;

bool cmp(pair<string,string> a,pair<string,string> b){
	return a.first<b.first || a.first==b.first && a.second<b.second;
}

vector<string> split(string str, string pattern) {
    vector<string> result;
    size_t pos=0;
    while ((pos = str.find(pattern)) != string::npos) {
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + pattern.length());
    }
    result.push_back(str);
    return result;        
}

int main(){
	vector<vector<pair<string,string>>> report;
	int n;
	string d=" ";
	while(cin >> n){
		if(!n) break;
		vector<pair<string,string>> day;
		cin.ignore();
		for(int i=0 ; i<n ; ++i){
			string tmp,name;
			getline(cin,tmp);
			vector<string> customer;
			customer = split(tmp,d);
			name = customer[0];			
			for(int j=1 ; j<customer.size();++j){
				string dish=customer[j];
				day.push_back(make_pair(dish,name));
			}
		}
		sort(day.begin(),day.end(),cmp);
		report.push_back(day);
	}
	for(int i=0 ; i<report.size() ; ++i){
		string tmp_dish=report[i][0].first;
		for(int j=0 ; j<report[i].size() ; ++j){
			if(!j) cout << tmp_dish << " " << report[i][0].second;
			else if(report[i][j].first != tmp_dish){
				tmp_dish = report[i][j].first;
				cout << endl << tmp_dish << " " << report[i][j].second;
			}
			else{
				cout << " " << report[i][j].second;
			}
		}
		cout << endl << endl;
	}
	return 0;
}
