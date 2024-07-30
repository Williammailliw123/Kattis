#include<bits/stdc++.h>
using namespace std;

int main(){
    int C;
    cin >> C;
    for(int i=0 ; i<C ; ++i){
        int N;
        cin >> N;
        vector<int> tmp(N);
        double avg=0;
        for(int j=0 ; j<N ; ++j){
            cin >> tmp[j];
            avg+=tmp[j];
        }
        avg/=N;
        double cnt=0;
        for(int j=0 ; j<N ; ++j) if(tmp[j] > avg) cnt=cnt+1;
        cnt=cnt*100/double(N);
        //cout << cnt << endl;
        //cnt=(cnt*1000+0.5)/1000;
        cout << fixed << setprecision(3) << cnt << "%\n";
    }
    system("pause");
}