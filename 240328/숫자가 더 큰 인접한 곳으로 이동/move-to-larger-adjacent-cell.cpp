#include <iostream>
#include<vector>
using namespace std;

vector<int> v;
int n,r,c;
int arr[101][101];

void input(){
    cin>>n>>r>>c;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    r-=1; c-=1;
    v.push_back(arr[r][c]);
}

bool move(){
    bool result = false;
    int dx[] ={-1,1,0,0};
    int dy[] ={0,0,-1,1};

    for(int i =0; i<4; i++){
        int nx = dx[i] + r;
        int ny = dy[i] + c;
        if(nx < 0|| ny < 0|| nx >=n || ny >=n) continue;
        if(arr[nx][ny] > arr[r][c]){
            r = nx; c = ny;
            v.push_back(arr[nx][ny]);
            return true;
        }
    }
    return result;
}

void print(){
    for(auto x : v) cout<<x<<' ';
}

void process(){
    //움직임이 없을 때 까지 반복. 
    //상 하 좌 우 우선순위로 수행 
    while(true)
    {   
        if(!move()) break;
    }

    print();
}

int main() {
    input();
    process();
    return 0;
}