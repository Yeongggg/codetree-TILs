#include <iostream>
#include<vector>

using namespace std;
int n,m;
vector<int> v;
void print(){
    for(auto x : v) cout<<x<<' ';
    cout<<'\n';
}
void Combination(int cur){
    if(cur == m){
        
            print();
            return;
        
    }
    //1. 중복을 허용하지 않는다.

    //2. 오름 차순으로 선택한다.
        // 각 단계에서의 시작지점이 1 부터 아닌 마지막으로 선택한 수 + 1부터 선정한다.
        
    int last = 0; //마지막으로 사용된 수
    if(cur >= 1){
        last = v[cur-1];
    }
    for(int i = last+1; i<=n; i++){
        
        v.push_back(i);
        Combination(cur+1);
        v.pop_back();
        
       
    }
}

int main() {
    cin>>n>>m;
    Combination(0);
    return 0;
}