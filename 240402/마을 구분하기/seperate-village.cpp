#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>

using namespace std;

int dx[]={0,1,0,-1};
int dy[] ={1,0,-1,0};
int arr[26][26];
int n;
int vis[26][26];
int cnt =0;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    vis[x][y] ==1;
    q.push({x,y});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i =0; i<4; i++){
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx <0 || ny <0 || nx >=n || ny >= n) continue;
            if(arr[nx][ny] == 1 && !vis[nx][ny]){
                vis[nx][ny] =1;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
}

int main() {
    cin>>n;
    for(int i =0;i<n; i++){
        for(int j =0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    vector<int> v;

      for(int i =0;i<n; i++){
        for(int j =0; j<n; j++){
        if(arr[i][j] == 1 && !vis[i][j]){
            bfs(i,j);
            v.push_back(cnt);
            cnt =0;
            }
        }
    }

    cout<<v.size()<<'\n';
    sort(v.begin(), v.end());
    for(auto x : v) cout<<x<<'\n';

    return 0;
}