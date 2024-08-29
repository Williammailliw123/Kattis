#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    while(cin >> k){
        for(int x=0 ; x<k ; ++x){
            int n,m;
            cin >> n >> m;
            vector<int> D(n);
            for(int i=0 ; i<n ; ++i) cin >> D[i];
            vector<int> left(n),right(n);
            int l=0,r=0,cum=0;
            bool flag=0;
            for(int i=0 ; i<n ; ++i){
                int cur=D[i];
                if(!flag){
                    if(cur>m){
                        l=i;
                        r=i;
                        cum+=cur;
                        flag=1;
                    }
                }
                else{
                    if(cur<=m){
                        right[l]=cum;
                        left[r]=cum;
                        cum=0;
                        flag=0;
                    }
                    else{
                        cum+=cur;
                        r+=1;
                    }
                }
                if(flag && i == n-1) right[l]=cum;
            }
            int result=0;
            for(int i=0 ; i<n ; ++i){
                if(D[i] == m){
                    if(!i) result=max(result,right[1]);
                    else if(i == n-1) result=max(result,left[n-2]);
                    else result=max(result,left[i-1]+right[i+1]);
                }
            }
            cout << result+m << endl;
        }
    }
}