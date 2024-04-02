#include <iostream>
#include<vector>

using namespace std;
int n; 
int arr[21][21];
int temp[21][21];
int k = 0;
vector<int> v;
vector<pair<int,int>> position;
int ans =0;

int dx[] ={-1,-2,1,2};
int dy[] ={0,0,0,0};

int dx_1[] ={1,-1,0,0};
int dy_1[] ={0,0,1,-1};

int dx_2[] ={-1,1,-1,1};
int dy_2[] ={-1,1,1,-1};

void initialize(){
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            temp[i][j] = arr[i][j];
        }
    }
}

void check_max(){
    int cnt =0;
     for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
          if(temp[i][j] == 1){
            cnt++;
          }
        }
    }
    if(ans < cnt) ans = cnt;
}


void check_bomb(){
    initialize();

    for(int i = 0; i<k; i++){
        int a = position[i].first;
        int b = position[i].second;

        if(v[i] == 0){
            for(int j =0; j<4; j++){
                int nx = a + dx[j];
                int ny = b + dy[j];
                if(nx < 0 || ny < 0 || nx >=n || ny >=n ) continue;
                temp[nx][ny] =1;
            }
        }else if(v[i] == 1){
            for(int j =0; j<4; j++){
                int nx = a + dx_1[j];
                int ny = b + dy_1[j];
                if(nx < 0 || ny < 0 || nx >=n || ny >=n ) continue;
                temp[nx][ny] =1;
            }
        }else if(v[i] == 2){
            for(int j =0; j<4; j++){
                int nx = a + dx_2[j];
                int ny = b + dy_2[j];
                if(nx < 0 || ny < 0 || nx >=n || ny >=n ) continue;
                temp[nx][ny] =1;
            }
        }
    }
    
    check_max();
}

void choose(int cur){
    if(cur == k){
        check_bomb();
        return;
    }
    /*
    폭탄의 종류에 따라 몇번 째 폭탄을 선택할 것인지 
    */
    for(int i =0; i<3; i++){
        v.push_back(i);
        choose(cur + 1);
        v.pop_back();
    }
    return;
}

int main() {
    cin>>n;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                k++;
                position.push_back({i,j});
                } 
        }
    }

    choose(0);
    cout<<ans;
    return 0;
}