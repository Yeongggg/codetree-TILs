#include <iostream>
#include<algorithm>
#include<cstdlib>

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
   
    for(int i =0; i<n; i++){
        for(int j =0; j<n-2; j++){
            for(int k=0; k<n; k++){
                for(int l=0; l <n-2; l++){
                    if(i == k && abs(j-2) <=2) continue;

                    int temp1 = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                    int temp2 = arr[k][l] + arr[k][l+1] + arr[k][l+2];

                    ans = max(ans, temp1+ temp2);                
                }
            }
        }   
    }
      
    
    cout<<ans;
    return 0;
}