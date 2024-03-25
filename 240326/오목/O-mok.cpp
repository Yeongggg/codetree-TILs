#include <iostream>
using namespace std;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
//dx dy 테크닉 필요
int board[19][19];


bool is_range(int x, int y){
    return x >=0 && x < 19 && y >=0 && y <19;
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
            int cur = board[i][j];
            if(cur == 0)continue;

            for(int k =0; k<8; k++){
                bool isWin = true;
                for(int l =0; l <5; l++){
                    int nx = i +(dx[k] * l);
                    int ny = j +(dy[k] * l);
                    isWin = isWin && is_range(nx,ny)&&board[nx][ny] == cur;
                }
                if(isWin){
                    cout<<cur<<'\n';
                    cout<<i+1+dx[k]*2<<' '<<j+1+dy[k]*2;
                return 0;
                }

                
            }
        }
    }
  
    cout<<0;
    // 여기에 코드를 작성해주세요.
    return 0;
}