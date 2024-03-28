#include <iostream>
using namespace std;
int n,t;
int arr[2][201];

void input(){
    cin>>n>>t;
    for(int i =0; i<n; i++) cin>>arr[0][i];
    for(int i = n-1; i>=0; i--) cin>>arr[1][i];
}

void move(){
    int temp1  = arr[1][0];
    int temp2 = arr[0][n-1];

    for(int i=0; i<n-1; i++){
        arr[1][i] = arr[1][i+1];
    }
    arr[1][n-1] = temp2;

    for(int i=n-1; i>0; i--){
        arr[0][i] = arr[0][i-1];
    }
    arr[0][0] = temp1;
}

void print(){
    for(int i =0; i<n; i++) cout<<arr[0][i]<<' ';
    cout<<'\n';
    for(int i = n-1; i>=0; i--) cout<<arr[1][i]<<' ';
}

void process(){

    while(t--){
        //시계방향으로 돌림
        move();
    }
    //숫자들을 출력
    print();
}
int main() {
    input();
    process();
    return 0;
}