#include <iostream>
#include <queue>
#include<cstring>

using namespace std;
int n,k;
int arr[101][101];
int vis[101][101];
int start_r, start_c;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int end_r, end_c;

// 1.시작 위치에서 출발해 인접한 칸들 중 적혀있는 숫자가 작은 곳으로 전부 이동 가능 -> bfs

// 2. 1을 만족하는 조건중 최대값으로 이동.

// 3. 최대값이 여러개인 경우, 행, 열 이 가장 작은 값으로 선정. -> 완전 탐색시 발견하면 break

// 4. k번 반복 후 위치를 구할 수 있어야함. K 번 반복하지 못해도 이동할 위치가 없다면, 종료.

void input(){
    // n 과 k 그리고 2차원 배열을 입력 받는다.
    cin>>n>>k;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    //시작점 위치를 입력 받는다.
    cin>>start_r >> start_c;
    start_r-=1;
    start_c-=1;
}
void bfs(int x, int y){
    // x,y 지점으로 부터 낮은 숫자는 (이동 가능한 칸) 모두 vis배열에서 1 로 될 것이다.
    queue<pair<int,int>> q;
    vis[x][y] =1;
    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i =0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx >=n || ny >=n)continue;
            if(arr[nx][ny] < arr[x][y] && !vis[nx][ny]){
                vis[nx][ny] =1;
                q.push({nx,ny});
            }
        }
    }
}
int check_max_num(){
    int num = 0;
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            if(i == start_r && j == start_c)continue;
            if(vis[i][j]){ 
                if(num < arr[i][j]) num = arr[i][j];
            }
        }
    }
    return num;
}

pair<int,int> check_position(int max_num){
    pair<int,int> result;
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
           if(vis[i][j]){
         
            if(arr[i][j] == max_num){
                
                result ={i,j};
                return result;
            }
           }
        }
    }
    return result;
}
void pro(){

    //행위를 k번 반복해야한다. 
    while(k--){
        //시작 위치에서 인접한 칸들 중 숫자가 작은 곳을 먼저 찾아 보자 (vis가 1 이라면 접근 가능)
        bfs(start_r, start_c);
        int max_num = check_max_num();
        

        auto position = check_position(max_num);
        end_r = position.first;
        end_c = position.second;
        
        if(start_c == end_c && end_r == start_r){
            break; //더이상 움직임이 없을 때 종료.
        }
        //그렇지 않은 경우 시작위치 변경 및 vis배열 초기화
        start_c = end_c;
        start_r = end_r;
        memset(vis,0,sizeof(vis));
    }
    cout<<start_r+1<<' '<<start_c+1;
}

int main() {
    input();
    pro();
    return 0;
}