#include <iostream>
using namespace std;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
//dx dy 테크닉 필요
int board[19][19];
int direction = 0;

bool is_five(int x, int y){
    bool result = false;
    int cnt = 1;
    for(int i =0; i<8; i++){
        int nx  = x + dx[i];
        int ny = y +dy[i];
        if(nx < 0 || ny <0 || nx >= 19 || ny >= 19) continue;
        for(int j =0; j<4; j++){
            if(board[x][y] == board[nx][ny]) cnt++;
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || ny <0 || nx >= 19 || ny >= 19) continue;
        }
        if(cnt == 5){
            result = true;
            direction = i;
            return result;
        }
        cnt = 0;
    }
    return result;

}
int main() {
    for(int i =0; i<19; i++){
        for(int j =0; j<19; j++){
            cin>>board[i][j];
        }
    }

    int win = 0;
    int x, y;
    for(int i =0; i<19; i++){
        for(int j =0; j<19; j++){
            if(board[i][j] == 1){
               if(is_five(i,j)){
                cout<<1<<'\n';
                if(direction == 0){
                    cout<<i+1 << ' '<< j+3;
                    return 0;
                }else if(direction == 1){
                    cout<<i+3<< ' '<< j+3;
                    return 0;
                }else if(direction == 2){
                    cout<<i+3 << ' '<< j;
                    return 0;
                }else if(direction == 3){
                    cout<<i+3 << ' '<< j-1;
                    return 0;
                }else if(direction == 4){
                    cout<<i+1 << ' '<< j-1;
                    return 0;
                }else if(direction == 5){
                    cout<<i-1 << ' '<< j-1;
                    return 0;
                }else if(direction == 6){
                    cout<<i-1 << ' '<< j+1;
                    return 0;
                }else if(direction == 7){
                    cout<<i-1 << ' '<< j+3;
                    return 0;
                }
               }
                          
                }else if(board[i][j] == 2){
                  
                    if(is_five(i,j)){
                cout<<2<<'\n';
                if(direction == 0){
                    cout<<i+1 << ' '<< j+3;
                    return 0;
                }else if(direction == 1){
                    cout<<i+3<< ' '<< j+3;
                    return 0;
                }else if(direction == 2){
                    cout<<i+3 << ' '<< j;
                    return 0;
                }else if(direction == 3){
                    cout<<i+3 << ' '<< j-1;
                    return 0;
                }else if(direction == 4){
                    cout<<i+1 << ' '<< j-1;
                    return 0;
                }else if(direction == 5){
                    cout<<i-1 << ' '<< j-1;
                    return 0;
                }else if(direction == 6){
                    cout<<i-1 << ' '<< j+1;
                    return 0;
                }else if(direction == 7){
                    cout<<i-1 << ' '<< j+3;
                    return 0;
                }
                    }
                }
            }
        }
  

    // 여기에 코드를 작성해주세요.
    return 0;
}