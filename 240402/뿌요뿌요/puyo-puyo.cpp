#include <iostream>
#include<queue>

using namespace std;
int max_block =0;
int cnt =0;
int n;
int arr[101][101];
int vis[101][101];
int dx[] ={0,1,0,-1};
int dy[] ={1,0,-1,0};

int bfs(int x, int y){
    int block = 1;
    vis[x][y] =1;
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i =0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx >=n || ny >=n)continue;
            if(arr[nx][ny] == arr[cur.first][cur.second] && !vis[nx][ny]){
                block++;
                vis[nx][ny] =1;
                q.push({nx,ny});
            }
        }
    }
    return block;
}

int main() {
    cin>>n;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }


    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
           if(!vis[i][j]){
            int temp = bfs(i,j);
            if(temp > max_block){
                max_block =temp;
            }
            if(temp >= 4) cnt++;
           }
        }
    }
    cout<<cnt<<' '<<max_block;
    return 0;
}