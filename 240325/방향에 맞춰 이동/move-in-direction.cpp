#include <iostream>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main() {
    int N; cin>>N;

    int x =0; int y= 0;
    int dir =0;
    while(N--){
        char cmd; cin>>cmd;
        int temp; cin >> temp;
        if(cmd == 'E'){
            dir =0;
        }else if(cmd == 'W'){
            dir = 1;
        }else if (cmd == 'N'){
            dir = 2;
        }else {
            dir = 3;
        }
        x+=dx[dir]*temp;
        y+=dy[dir]*temp;


    }
    cout<<x<<' '<<y;

    return 0;
}