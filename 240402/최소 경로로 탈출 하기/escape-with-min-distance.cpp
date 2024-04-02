#include <iostream>
#include<queue>
using namespace std;

int arr[101][101];
int dis[101][101];
int dx[] ={0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,m;

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    dis[x][y] =1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i =0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx >= n || ny >=m)continue;
            if(!dis[nx][ny] && arr[nx][ny] == 1){
                //bfs 탐색은 항상 가까운 정점을 기준으로 탐색하기에 최단거리 유지(가중치가 동일 하므로)
                dis[nx][ny] = dis[cur.first][cur.second] + 1;
                q.push({nx,ny});
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    bfs(0,0);
    cout<<dis[n-1][m-1]-1;    
    return 0;
}