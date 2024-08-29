#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> left(201,vector<int> (201,-1));
    vector<vector<int>> up(201,vector<int> (201,-1));
    vector<vector<int>> right(201,vector<int> (201,-1));
    vector<vector<int>> down(201,vector<int> (201,-1));
    int loc_x=100,loc_y=100;
    while(1){
        string ins;
        if(left[loc_x][loc_y] == -1 && right[loc_x-1][loc_y] == -1) ins="left";
        else if(up[loc_x][loc_y] == -1 && down[loc_x][loc_y+1] == -1) ins="up";
        else if(right[loc_x][loc_y] == -1 && left[loc_x+1][loc_y] == -1) ins="right";
        else if(down[loc_x][loc_y] == -1 && up[loc_x][loc_y-1] == -1) ins="down";
        else if(left[loc_x][loc_y] == -1) ins="left";
        else if(up[loc_x][loc_y] == -1) ins="up";
        else if(right[loc_x][loc_y] == -1) ins="right";
        else if(down[loc_x][loc_y] == -1) ins="down";
        else ins="no way out";
        cout << ins << endl;
        //cout << flush;
        string response;
        cin >> response;
        if(response == "solved" || response == "wrong") break;
        if(response == "wall"){
            if(ins == "left"){
                left[loc_x][loc_y]=0;
                right[loc_x-1][loc_y]=0;
            }
            else if(ins == "up"){
                up[loc_x][loc_y]=0;
                down[loc_x][loc_y+1]=0;
            }
            else if(ins == "right"){
                right[loc_x][loc_y]=0;
                left[loc_x+1][loc_y]=0;
            }
            else if(ins == "down"){
                down[loc_x][loc_y]=0;
                up[loc_x][loc_y-1]=0;
            }
        }
        else if(response == "ok"){
            if(ins == "left"){
                left[loc_x][loc_y]=1;
                --loc_x;
            }
            else if(ins == "up"){
                up[loc_x][loc_y]=1;
                ++loc_y;
            }
            else if(ins == "right"){
                right[loc_x][loc_y]=1;
                ++loc_x;
            }
            else if(ins == "down"){
                down[loc_x][loc_y]=1;
                --loc_y;
            }
        }
    }
}