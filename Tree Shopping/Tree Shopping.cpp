#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main(){
	int n,k;
	while(cin >> n >> k){
		vector<int> D(n);
		priority_queue<pair<int,int>> MAX;
		priority_queue<pi, vector<pi>, greater<pi>> MIN;
		int tmp;
		for(int i=0 ; i<n ; ++i){
			cin >> tmp;
			if(i<k){
				MAX.push(make_pair(tmp,i));
				MIN.push(make_pair(tmp,i));
			}
			D[i]=tmp;
		}
		int result=MAX.top().first-MIN.top().first;
		for(int i=1 ; i<n-k+1 ; ++i){
			while(MAX.top().second<i || MAX.top().second>=i+k) MAX.pop();
			while(MIN.top().second<i || MIN.top().second>=i+k) MIN.pop();
			MAX.push(make_pair(D[i+k-1],i+k-1));
			MIN.push(make_pair(D[i+k-1],i+k-1));
			result=min(result,MAX.top().first-MIN.top().first);
		}
		cout << result << endl;
	}
	return 0;
}
