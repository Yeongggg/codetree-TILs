#include <iostream>
#include <algorithm>
using namespace std;

int a[21][21];
int calCoin(int i, int j){
    int cnt =0;
    for(int x = i; x<= i+2; x++){
        for(int y =j; y<=j+2; y++ ){
            if(a[x][y] == 1) cnt++;
        }
    }
    return cnt;
}
int main() {
    int n; cin>>n;
    for(int i =0; i<n; i++) {
        for(int j =0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(i+2 >= n || j+2 >=n)continue;
            int temp = calCoin(i,j);
            ans = max(ans, temp);
        }
    }
    cout<<ans;
    return 0;
}