#include <iostream>

using namespace std;
int dx[] ={0,1,0,-1};
int dy[]={1,0,-1,0};

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m; cin>>n>>m;
    int temp = n*m;
    int start =1;
    int dir = 0;
   
    int x =0; int y =0;

    int arr[101][101];
    
    for(int i =0; i<temp; i++){
        arr[x][y] = start++;
        
        int nx = x + dx[dir];
        int ny = y+ dy[dir];

        if(nx <0 || ny <0 || nx >=n || ny >= m || arr[nx][ny] != 0) {
            dir = (dir+1)%4;
        }
        x+=dx[dir]; y +=dy[dir];
    }

    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cout<<arr[i][j]<<' ';
        }cout<<'\n';
    }
    return 0;
}