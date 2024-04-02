#include <iostream>
#include <vector>
using namespace std;

int visited[1001];
vector<int> v[1001];
int cnt = 0;
int n,m;

void dfs(int node){
    visited[node] =1;
   for(int i =0; i<v[node].size(); i++){
    
    int cur = v[node][i];
    if(!visited[cur]){
        cnt++;
        dfs(cur);
    }

   }
}

int main() {
    cin>>n>>m;

    for(int i =0; i<m; i++){
        int a,b; cin>> a>> b;
        v[a].push_back(b);
        v[b].push_back(a);

    }


    dfs(1);

    cout<<cnt;
    return 0;
}