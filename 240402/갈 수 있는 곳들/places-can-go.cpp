#include <iostream>
#include <queue>
#include<cstring>
#include<vector>

using namespace std;

int n,k;
int arr[101][101];

int dx[] ={0,1,0,-1};
int dy[] ={1,0,-1,0};
int visited[101][101];
vector<pair<int,int>> v;

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i =0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || ny <0 || ny >=n || nx >= n)continue;
            if(arr[nx][ny] == 0 && !visited[nx][ny]){
                arr[nx][ny] = 2;
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    
    cin>>n>>k;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i =0; i<k; i++){
        int x,y; cin>>x>>y;
       v.push_back({x-1,y-1});
       arr[x-1][y-1] = 2;
    }
    for(auto cur : v){
    bfs(cur.first, cur.second);
    }

    int cnt =0;
  
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 2) cnt++;

        }
    }
 
    cout<<cnt;

    return 0;
}