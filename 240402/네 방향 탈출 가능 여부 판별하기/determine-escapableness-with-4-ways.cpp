#include <iostream>
#include<queue>

using namespace std;

int dx[] ={0,1,0,-1};
int dy[] ={1,0,-1,0};
int arr[101][101];
int visited[101][101];
int n,m;

void bfs(int x, int y){
    //bfs탐색을 위한 queue 생성
    queue<pair<int,int>> q;
    q.push({x,y});
    //해당 칸 방문 처리
    visited[x][y] =1;

    //queue가 비워질떄 까지 bfs 탐색 
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i =0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx >=n || ny >= m)continue; //범위에서 벗어나는 경우
            if(!visited[nx][ny] && arr[nx][ny]) //방문하지 않았고 뱀이 존재하지 않는다면
            {
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    bfs(0,0);
    if(visited[n-1][m-1] == 1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}