#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}

int main(){
	int n;
	while(cin >> n){
		string s;
		char c;
		int month,day;
		vector<char> tmp_date(5);
		vector<int> record;
		for(int i=0 ; i<n ; ++i){
			cin >> s >> month >> c >> day;
			if(month == 1) record.push_back(day);
			else if(month == 2) record.push_back(31+day);
			else if(month == 3) record.push_back(59+day);
			else if(month == 4) record.push_back(90+day);
			else if(month == 5) record.push_back(120+day);
			else if(month == 6) record.push_back(151+day);
			else if(month == 7) record.push_back(181+day);
			else if(month == 8) record.push_back(212+day);
			else if(month == 9) record.push_back(243+day);
			else if(month == 10) record.push_back(273+day);
			else if(month == 11) record.push_back(304+day);
			else if(month == 12) record.push_back(334+day);
		}
		sort(record.begin(),record.end());
		//for(int i=0 ; i<n ; ++i) cout << record[i] << endl;
		vector<pair<int,int>> interval;
		for(int i=0 ; i<n-1 ; ++i) interval.push_back(make_pair(record[i+1]-record[i],i));
		interval.push_back(make_pair(365+record[0]-record[n-1],n-1));
		sort(interval.begin(),interval.end(),cmp);
		vector<int> longest;
		for(int i=0 ; i<n ; ++i){
			longest.push_back(record[interval[i].second]+interval[i].first-1);
			if(i+1>=n || interval[i+1].first<interval[i].first) break;
		}
		int result,tmp1=1000,tmp2;
		for(int i=0 ; i<longest.size() ; ++i){
			if(longest[i]>=301) tmp2=longest[i]-301;
			else tmp2=longest[i]+365-301;
			if(tmp2<tmp1){
				result=longest[i];
				tmp1=tmp2;
			}
		}
		if(result>365) result-=365;
		int result_m,result_d;
		if(result<=31){
			result_m=1;
			result_d=result;
		}
		else if(result<=59){
			result_m=2;
			result_d=result-31;
		}
		else if(result<=90){
			result_m=3;
			result_d=result-59;
		}
		else if(result<=120){
			result_m=4;
			result_d=result-90;
		}
		else if(result<=151){
			result_m=5;
			result_d=result-120;
		}
		else if(result<=181){
			result_m=6;
			result_d=result-151;
		}
		else if(result<=212){
			result_m=7;
			result_d=result-181;
		}
		else if(result<=243){
			result_m=8;
			result_d=result-212;
		}
		else if(result<=273){
			result_m=9;
			result_d=result-243;
		}
		else if(result<=304){
			result_m=10;
			result_d=result-273;
		}
		else if(result<=334){
			result_m=11;
			result_d=result-304;
		}
		else if(result<=365){
			result_m=12;
			result_d=result-334;
		}
		cout << setw(2) << setfill('0') << result_m << "-" << setw(2) << setfill('0') << result_d << endl;
	}
	return 0;
} 
