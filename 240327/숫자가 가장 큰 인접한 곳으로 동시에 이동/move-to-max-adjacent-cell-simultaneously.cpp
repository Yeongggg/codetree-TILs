#include <iostream>
#include<cstring>

#define MAXN 21
using namespace std;

int n,m,t;
int board[MAXN][MAXN]; // a[][] 격자에 적힌 수의 정보
int cnt[MAXN][MAXN]; // 각 격자에 존재하는 구슬의 개수 정보 
int temp[MAXN][MAXN]; // 구슬이 이동한 결과를 담는 cnt 배열의 복사본 
// Skeleton Code

//입력 받는 함수 
void input(){
    //격자와 구슬의 위치를 받는다.
    cin>> n>> m >> t;

    for(int i =1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cin>> board[i][j];
        }
    }

    for(int i =1; i<=m; i++){
        int r,c;
        cin >> r >> c;
        cnt[r][c] = 1; //모든 구슬의 시작 위치는 서로 다르다고 가정 가능
    }

}

// 충돌한 구슬들 삭제하기 
void RemoveDuplicate(){

    //모든 격자에 대해서 구슬이 2개 이상인 위치는 0 으로 바꿔준다.
    for(int i =1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(cnt[i][j] >=2) cnt[i][j] =0;
        }
    }
}

void Move(int i, int j){
    // 상 하 좌 우 로 인접한 칸 중 어디로 이동할 지 결정해야함.
    int maxValue = 0, maxI, maxJ;
    //maxValue : 발견한 가장 큰 값
    //maxI, maxJ : 가장 큰값에 해당하는 격자 좌표 
    // 상 -> 하 -> 좌 -> 우 순서대로 이전보다 큰 값에 대해서만 업데이트 해주면 된다.
    // 우선순위가 위와 같은 경우 이므로, 같은 값에 대해서도 무관함.
    int dx[] ={-1,1,0,0};
    int dy[] ={0,0,-1,1};

    for(int k=0; k<4; k++){
        int nx = dx[k] + i;
        int ny = dy[k] + j;

        if(nx <=0 || ny <= 0 || nx > n || ny > n || maxValue > board[nx][ny]) continue;
        maxValue = board[nx][ny];
        maxI = nx;
        maxJ = ny;
    } 

    //해당 위치로 구슬을 이동시킨다.
    temp[maxI][maxJ] +=1;
    
}


void moveAll(){
    //1초 뒤 상황을 저장할 배열을 초기화 하기.
    memset(temp,0,sizeof(temp));

    // 구슬을 찾아서 이동시키기
    for(int i= 1; i<=n; i++){
        for(int j =1; j<=n; j++){
            if(cnt[i][j] == 1){
                //i행 j열에 구슬이 존재한다.
                Move(i,j); // i행 j열의 구슬을 이동시키는 구슬
            }
        }
    }
    for(int i =1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cnt[i][j] = temp[i][j];
        }
    }
}

//문제를 해결하는 함수 
void process(){
    //t 초 동안 시뮬레이션을 구현해야 한다. 
    while(t--){
        // 1. 각 구슬을 조건에 맞게 이동 시킴
        moveAll();
        // 2. 충돌한 구슬에 대한 처리 (삭제)
        RemoveDuplicate();
    }
    // 남아있는 구슬의 개수 계산하기
    int ans =0;
    for(int i =1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans+= cnt[i][j];
        }
    }
    cout<<ans;
}

int main() {
    input();
    process();
    return 0;
}