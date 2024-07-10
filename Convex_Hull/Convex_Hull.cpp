#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll low_y,low_x;

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	if(a.second == low_y && b.second == low_y) return a.first>b.first;
	else if(a.second == low_y) return a.first+100000>b.first;
	else if(b.second == low_y) return a.first>b.first+100000;
	else return (a.first-low_x)*(b.second-low_y) > (b.first-low_x)*(a.second-low_y)
				|| (a.first-low_x)*(b.second-low_y) == (b.first-low_x)*(a.second-low_y) && a.second > b.second;
}

int main(){
	cout.sync_with_stdio(false);
	ll n;
	while(cin >> n){
		if(!n) break;
		vector<pair<ll,ll>> rec(n);
		ll low_id;
		low_x=100000,low_y=100000;
		for(ll i=0 ; i<n ; ++i){
			cin >> rec[i].first >> rec[i].second;
			if(rec[i].second < low_y || rec[i].second == low_y && rec[i].first < low_x){
				low_id=i;
				low_y=rec[i].second;
				low_x=rec[i].first;
			}
		}
		pair<ll,ll> tmp=rec[low_id];
		rec[low_id]=rec[0];
		rec[0]=tmp;
		sort(rec.begin()+1,rec.end(),cmp);
		stack<pair<ll,ll>> t;
		for(ll i=n-1 ; i>=0 ; --i) t.push(rec[i]);
		vector<pair<ll,ll>> R;
		pair<ll,ll> p=make_pair(100000,100000);
		R.push_back(t.top());
		t.pop();
		ll px,py;
		if(n>=2 && t.top() != R[0]){
			px=t.top().first-low_x;
			py=t.top().second-low_y;
			R.push_back(t.top());
			t.pop();
		}
		for(ll i=2 ; i<n ; ++i){
			pair<ll,ll> q=t.top();
			t.pop();
			if(q == p || px*(q.second-low_y)-py*(q.first-low_x) == 0) continue;
			R.push_back(q);
			p=q;
			px=q.first-low_x;
			py=q.second-low_y;
		}
		
		if(R.size() == 1){
			cout << "1\n" << R[0].first << " " << R[0].second << endl;
			continue;
		}
		else if(R.size() == 2){
			cout << "2\n" << R[0].first << " " << R[0].second << endl << R[1].first << " " << R[1].second << endl;
			continue;
		}
		stack<pair<ll,ll>> S;
		S.push(R[0]);
		S.push(R[1]);
		S.push(R[2]);
		for(ll i=3 ; i<R.size() ; ++i){
			bool flag=0,same=0;
			while(!flag){
				pair<ll,ll> t1,t2;
				t1=S.top();
				S.pop();
				t2=S.top();
				S.push(t1);
				ll t2_t1_x=t1.first-t2.first,t2_t1_y=t1.second-t2.second,t1_p_x=R[i].first-t1.first,t1_p_y=R[i].second-t1.second;
				if(t2_t1_x*t1_p_y-t1_p_x*t2_t1_y <= 0) S.pop();
				else flag=1;
			}
			S.push(R[i]);
		}
		vector<pair<ll,ll>> result(S.size());
		for(ll i=S.size()-1 ; i>=0 ; --i){
			result[i]=S.top();
			S.pop();
		}
		cout << result.size() << endl;
		//cout << low_x << " " << low_y << endl;
		//for(ll i=0 ; i<R.size() ; ++i) cout << R[i].first << " " << R[i].second << endl;
		for(ll i=0 ; i<result.size() ; ++i) cout << result[i].first << " " << result[i].second << endl;
	}
}
