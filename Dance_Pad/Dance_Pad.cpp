#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(cin >> N){
        vector<string> rec(N);
        vector<int> UU,HH,NN,VV;
        for(int i=0 ; i<N ; ++i){
            cin >> rec[i];
            for(int j=0 ; j<rec[i].size() ; ++j){
                char c=rec[i][j];
                if(c == 'U') UU.push_back(i);
                else if(c == 'H') HH.push_back(i);
                else if(c == 'N') NN.push_back(i);
                else VV.push_back(i);
            }
        }
        UU.push_back(100000);
        HH.push_back(100000);
        NN.push_back(100000);
        VV.push_back(100000);
        char x='V',y='H';
        int u=0,h=0,n=0,v=0;
        int result=0;
        for(int i=0 ; i<N ; ++i){
            //cout << x << ' ' << y << endl;
            string cur=rec[i];
            if(cur.size() == 2){
                char a=cur[0],b=cur[1];
                if(x != a && x != b && y != a && y != b){
                    x=a;
                    y=b;
                    result+=2;
                }
                else if(x == a && y != b){
                    y=b;
                    ++result;
                }
                else if(x == b && y != a){
                    y=a;
                    ++result;
                }
                else if(y == a && x != b){
                    x=b;
                    ++result;
                }
                else if(y == b && x != a){
                    x=a;
                    ++result;
                }
                if(a == 'U' || b == 'U') ++u;
                if(a == 'H' || b == 'H') ++h;
                if(a == 'N' || b == 'N') ++n;
                if(a == 'V' || b == 'V') ++v;
            }
            else{
                char c=cur[0];
                if(x != c && y != c){
                    int sc_x,sc_y;
                    if(x == 'U') sc_x=UU[u]-i;
                    else if(x == 'H') sc_x=HH[h]-i;
                    else if(x == 'N') sc_x=NN[n]-i;
                    else sc_x=VV[v]-i;
                    if(y == 'U') sc_y=UU[u]-i;
                    else if(y == 'H') sc_y=HH[h]-i;
                    else if(y == 'N') sc_y=NN[n]-i;
                    else sc_y=VV[v]-i;
                    if(sc_x<sc_y) y=c;
                    else x=c;
                    ++result;
                }
                if(c == 'U') ++u;
                else if(c == 'H') ++h;
                else if(c == 'N') ++n;
                else ++v;
            }
        }
        cout << result << endl;
    }
}