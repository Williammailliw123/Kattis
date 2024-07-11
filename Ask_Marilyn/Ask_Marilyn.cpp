#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    for(int i=0 ; i<1000 ; ++i){
        int tmp=rand()%3;
        if(!tmp) cout << "A\n";
        else if(tmp == 1) cout << "B\n";
        else cout << "C\n";
        char C;
        bool b;
        cin >> C >> b;
        char ans;
        if(b) ans=C;
        else{
            if(C == 'A'){
                if(tmp == 1) ans='C';
                else ans='B';
            }
            else if(C == 'B'){
                if(tmp == 0) ans='C';
                else ans='A';
            }
            else if(C == 'C'){
                if(tmp == 0) ans='B';
                else ans='A';
            }
        }
        cout << ans << endl;
        cin >> b >> C;
    }
}
