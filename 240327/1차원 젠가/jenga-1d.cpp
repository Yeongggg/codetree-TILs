#include <iostream>
using namespace std;
int arr[101];

int total = 0;

void curArr(int s, int e){
    int temp[101];
    int total_temp =0;

    for(int i =0; i<total; i++){
        if(i <s || i > e){
            temp[total_temp++] = arr[i];
        }
    }
    for(int i =0; i<total_temp; i++){
        arr[i] = temp[i];
    }
    total  = total_temp;
}

int main() {
    int n; cin>>n; for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    
    total = n;

    for(int i =0; i<2; i++){
        int s,e; cin>>s>>e;
      
        e-=1; s-=1;
       curArr(s,e);
    }
    cout<<total<<'\n';
    for(int i =0; i<total; i++) cout<<arr[i]<<'\n';

    return 0;
}