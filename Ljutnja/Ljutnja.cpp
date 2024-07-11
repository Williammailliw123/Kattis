#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N,M;
	while(cin >> M >> N){
		priority_queue<long long,vector<long long>,greater<long long>> D;
		long long tmp,sum=0;
		for(int i=0 ; i<N ; ++i){
			cin >> tmp;			
			if(tmp>0){
				sum+=tmp;
				D.push(tmp);
			}
		}
		long long diff=sum-M,loop=0;
		unordered_map<long long,long long> record;
		while(1){			
			if(diff<=D.size()){
				if(record.count(loop)) record[loop]+=D.size()-diff;
				else record[loop]=D.size()-diff;
				record[loop+1]=diff;
				break;
			}
			else{
				long long sub=diff/D.size();
				long long cnt=0;
				if(sub+loop<=D.top()){
					loop+=sub;
					diff-=sub*D.size();
					while(D.top() == loop){
						++cnt;
						D.pop();
					}
					record[loop]=cnt;
				}
				else{					
					diff-=(D.top()-loop)*D.size();
					loop=D.top();
					while(D.top() == loop){
						++cnt;
						D.pop();
					}
					record[loop]=cnt;
				}				
			}									
		}
		unsigned long long result=0;
		for(const auto& s : record){
        	result+=s.first*s.first*s.second;
    	}
    	cout << result << endl;
	}
	return 0;
}
