#include <iostream>
#include<queue>
#include<cstring>

using namespace std;
int arr[51][51];
int vis [51][51];

int dx[] = {0,1,0,-1};
int dy[] ={1,0,-1,0};
int safe =0;
int max_k = 1;
int n,m;

void bfs(int x,int y, int k){
    queue<pair<int,int>> q;
    vis[x][y] =1;
    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i =0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || nx >=n || ny >=m) continue;
            if(arr[nx][ny] > k && !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny] = 1;

            }
        }
    }
}
int main() {
    cin>>n>>m;
    int max_num = 0;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
            if(max_num < arr[i][j]) max_num = arr[i][j];
        }
    }
    int k = 1;
    while(k <= max_num){
        memset(vis,0,sizeof(vis));
        int temp =0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
             if(arr[i][j] > k && !vis[i][j]){
                bfs(i,j,k);
                temp++;
                }
            }
        }
        if(safe < temp){
            safe = temp;
            max_k = k;
        }
        k++;
    }
    cout<<max_k<<' '<<safe;
    return 0;
}