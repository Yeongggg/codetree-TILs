#include <iostream>
#include <string>

using namespace std;

int dx[] ={0,1,0,-1,-1,1,1,-1};
int dy[] ={1,0,-1,0,1,1,-1,-1};

int main() {
    int n,m; cin>>n>>m;
    string s[51];
    for(int i =0; i<n; i++){
        cin>>s[i];
    }
    int ans =0;

    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j] == 'L'){
               for(int k=0; k<8; k++){
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                if(nx < 0 || ny <0 || nx >=n || ny >= m)continue;
                int nnx = nx+dx[k];
                int nny = ny +dy[k];
                if(nx + dx[k] < 0 || ny + dy[k] <0 || nx +dx[k] >=n || ny +dy[k] >= m)continue;
                if(s[nx][ny] == 'E' && s[nnx][nny] =='E') ans++;   
               }
            }
        }
    }
    cout<<ans;
    return 0;
}