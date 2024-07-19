#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,T,S;
    while(cin >> N >> T >> S){
        vector<pair<int,int>> ad(N);
        for(int i=0 ; i<N ; ++i){
            int a,b;
            cin >> a >> b;
            ad[i]=make_pair(a,b);
        }
        int cur_start=0,cur_end=S,last_id=0,result=S;
        bool rem=0;
        while(1){
            if(last_id>=N) break;
            else if(ad[last_id].second<=cur_end){            
                result-=ad[last_id].second-ad[last_id].first;
                ++last_id;
            }
            else if(ad[last_id].first>=cur_end) break;
            else{
                result-=cur_end-ad[last_id].first;
                rem=1;
                break;
            }
        }
        int first_id=0,tmp_result=result;
        while(1){
            if(first_id>=N) break;
            if(ad[first_id].first+S > T){
                int next_start=T-S;
                int next_end=T;
                if(first_id>0) tmp_result+=min(next_start-ad[first_id-1].first,ad[first_id-1].second-ad[first_id-1].first);
                if(rem){
                	tmp_result-=ad[last_id].second-cur_end;
                	++last_id;
				}
                for(int i=last_id ; i<N ; ++i) tmp_result-=ad[i].second-ad[i].first;
                result=min(result,tmp_result);
                break;
            }
            int next_start=ad[first_id].first,next_end=cur_end-cur_start+ad[first_id].first;
            if(first_id>0) tmp_result+=ad[first_id-1].second-ad[first_id-1].first;
            if(rem){
                if(ad[last_id].second>=next_end){
                    tmp_result-=next_end-cur_end;
                    if(ad[last_id].second == next_end){
                        rem=0;
                        ++last_id;
                    }
                }
                else{
                    tmp_result-=ad[last_id].second-cur_end;
                    rem=0;
                    ++last_id;
                }
            }
            if(!rem){
                for(int i=last_id ; i<N ; ++i){
                    if(ad[last_id].second<=next_end){
                        tmp_result-=ad[last_id].second-ad[last_id].first;
                        ++last_id;
                    }
                    else if(ad[last_id].first>=next_end) break;
                    else{
                        tmp_result-=next_end-ad[last_id].first;
                        rem=1;
                        break;
                    }
                }
            }
            result=min(result,tmp_result);
            cur_start=next_start;
            cur_end=next_end;
            ++first_id;
        }
        cout << result << endl;
    }
}
