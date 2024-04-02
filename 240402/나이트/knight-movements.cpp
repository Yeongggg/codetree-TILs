#include <iostream>
#include <queue>

using namespace std;
int r1,r2,c1,c2;

int arr[101][101];
int dis[101][101];
int n;
int dx[] ={-2,-1,1,2,2,1,-1,2};
int dy[] ={1,2,2,1,-1,-2,-2,-1};

void bfs(int x, int y){
    dis[x][y] = 1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i =0; i<8; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx >=n || ny >= n) continue;
            if(dis[nx][ny] == 0){
                q.push({nx,ny});
                dis[nx][ny] = dis[cur.first][cur.second] + 1;
            }
        }
    }
   
}


int main() {

    cin >> n;
    cin>>r1>>c1>>r2>>c2;

    bfs(r1-1,c1-1);
    if(dis[r2-1][c2-1] == 0){
        cout<<-1;
    }else{
        cout<<dis[r2-1][c2-1]-1;
    }
    return 0;
}