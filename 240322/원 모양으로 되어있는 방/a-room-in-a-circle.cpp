#include <iostream>
#include<cstdlib>
#include<cmath>

using namespace std;


int main() {
   int arr[1003];
   int n; cin>>n;

   for(int i =0; i<n; i++) cin >> arr[i];
   int ans =987654321;
    for(int i =0; i<n; i++){
        int temp =0;
        for(int j =0; j<n; j++){
            int cost = 0;
            if(i > j){
                cost = arr[j] *(n-abs(i-j));    
            }else{
               cost = arr[j] *(abs(i-j));
            }
         
            temp += cost;
        }
       
        ans = min(ans, temp);
    }
    cout<<ans;
    return 0;
}