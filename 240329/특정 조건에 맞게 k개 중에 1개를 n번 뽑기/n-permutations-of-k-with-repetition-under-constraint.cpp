#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

int k,n; 

void print(){
    for(auto x : v){
        cout<<x<<' ';
    }cout<<'\n';
}
void choose(int cur){
    if(cur == n){
        print();
        return;
    }

    for(int i =1; i<=k; i++){
        
        if(cur <2 || v[cur-1] != i || v[cur-2]!= i){
           
            v.push_back(i);
            choose(cur+1);
            v.pop_back();
            
        }
        
    }
}

int main() {
    cin>>k>>n;
    choose(0);

    return 0;
}