#include <iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main() {
    int n,s; cin>>n>>s;

    int arr[101];
    int total = 0;
    for(int i =0; i<n; i++){
        cin >>arr[i];
        total += arr[i];
    } 

    int ans = 987654321;

    for(int i =0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int temp = total - (arr[i] + arr[j]);
            temp = abs(temp - s);
            ans = min(ans, temp);
        }
    }
    cout<<ans;
    
    return 0;
}