#include <iostream>
using namespace std;

int dx[] ={0,1,0,-1};
int dy[] = {1,0,-1,0};
int main() {
    int arr[101][101];

    int n; cin>>n;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    int cnt = 0;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            for(int k =0; k<4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
            
                if(nx < 0 || ny < 0 || nx >=n ||ny >=n)continue;
                if(arr[nx][ny] == 1)cnt++;
               
            }
            if(cnt >=3)ans++;
            cnt =0;
        }
    }
    cout<<ans;
    
    return 0;
}