#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
  int arr[101];
    int max_value = 0;

    for(int i =0; i<n; i++) cin>>arr[i];

    for(int i =0; i<n; i++){
      
        for(int j = i+ 2; j<n; j++){
           int temp = arr[i] + arr[j];
          
            max_value  = max(max_value, temp);
        }
    }
    cout<<max_value;
    return 0;
}