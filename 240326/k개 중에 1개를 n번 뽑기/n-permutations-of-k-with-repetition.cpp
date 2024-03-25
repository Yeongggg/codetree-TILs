#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
int N,k;

void print(){
    for(int i =0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }cout<<'\n';
}

void recur(int cnt){
    if(cnt == N){
        print();
        return;
    }
    for(int i =1; i<=k; i++){
        ans.push_back(i);
        recur(cnt+1);
        ans.pop_back();
    }
}

int main() {

    cin>>k>>N;
    recur(0);
    return 0;
}