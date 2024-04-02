#include <iostream>

using namespace std;

int dx[] = {1,0};
int dy[] = {0,1};
int n,m;
int arr[101][101];
int visited[101][101];
void dfs(int x, int y){
    visited[x][y] =1;
    for(int i =0; i<2; i++){
        int nx = x+ dx[i];
        int ny = y + dy[i];
        if(nx <0 || ny <0 || nx >=n || ny >=m) continue;
        if(arr[nx][ny]==1){
            visited[nx][ny] =1;
            dfs(nx,ny);
        } 
    }
}
int main() {
    cin>>n>>m;

    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,0);
    if(visited[n-1][m-1] == 1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}