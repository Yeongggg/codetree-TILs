#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    int n; cin>>n; 

    int arr[21][21];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }  
    int ans = 0;
    int temp = 0;
    int temp_i = 0;
    for(int i =0; i<n; i++){
        
        
      for(int j=0; j<n-2; j++){
        temp_i = arr[i][j] +arr[i][j+1]+ arr[i][j+2];

        for(int k = i+1; k<n; k++){
            for(int l =0; l<n-2; l++){
                 temp = arr[k][j] +arr[k][j+1]+ arr[k][j+2];
                 ans = max(ans,temp + temp_i);
            }
        }
      }
      
    }
    cout<<ans;
    return 0;
}