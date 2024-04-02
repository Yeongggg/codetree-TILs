#include <iostream>
#include <string>

using namespace std;

int dx[] ={-1,0,1,0}; //북 서 남 동
int dy[] ={0,-1,0,1};
int n,t;
int arr[101][101];

int main() {
    cin>>n>>t;
    string s;
    cin >>s;

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int x = n/2;
    int y= n/2;
    int total = arr[x][y];

    int dir = 0;
    for(int i =0; i<t; i++){
       if(s[i] == 'R'){
        dir = (dir + 4 - 1) % 4;
       }else if(s[i] == 'L'){
        dir = (dir + 1) % 4;
       }else if(s[i] == 'F'){
        
        int nx = x+dx[dir];
       int ny = y+dy[dir];
       if(nx < 0 || ny <0 || nx >=n || ny >=n )continue;
       x = nx; y = ny;
       total+=arr[nx][ny];
       }
      
            
        
    }
    cout<<total;
    return 0;
}