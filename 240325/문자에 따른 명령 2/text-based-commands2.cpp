#include <iostream>
#include<string>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] ={0,-1,0,1};
int main() {
    string s; cin>>s;
    int x =0; int y =0;
    int dir = 3;
    for(int i =0; i<s.size(); i++){
        if(s[i] == 'L'){
            dir--;
            if(dir < 0) dir = 3;
        }else if(s[i] == 'R'){
            dir++;
            if(dir > 3) dir = 0;
        }else{
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout<<x<<' '<<y;
    return 0;
}