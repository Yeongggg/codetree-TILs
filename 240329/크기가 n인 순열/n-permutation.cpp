#include <iostream>
#include<vector>
using namespace std;
vector<int> v;
int n;
bool check[9];
void print(){
    for(auto x: v) cout<<x<<' ';
    cout<<'\n';
}

void choose(int cnt){
    if(cnt == n){
        print();
        return;
    }

    for(int i =1; i<=n; i++){
        if(!check[i]){
            v.push_back(i);
            check[i] = true;

            choose(cnt+1);
            
            v.pop_back();
            check[i] =false;
        }

    }
}
int main() {
    cin>>n;
    choose(0);
    return 0;
}