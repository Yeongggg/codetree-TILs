#include <iostream>
#include <vector>

using namespace std;
int n,k; 
vector<int> v;

void print(){
    for(auto x : v) cout<<x<<' ';
    cout<<'\n';
}

void choose(int cur){
    if(cur == n+1){
        print();
        return;
    }

    for(int i =1; i<=k; i++){
        v.push_back(i);
        choose(cur + 1);
        v.pop_back();
    }
    return;
}

int main() {
    cin>>n>>k;
    choose(1);
    return 0;
}