#include <iostream>
#include <vector>
using namespace std;

int visited[1001];
vector<int> v[1001];

int n,m;

void dfs(int node){
    visited[node] =1;
   for(int i =0; i<v[node].size(); i++){
    
    int cur = v[node][i];
    if(!visited[cur]){
        dfs(cur);
    }

   }
}

int main() {
    cin>>n>>m;

    for(int i =0; i<m; i++){
        int a,b; cin>> a>> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);

    }
    int cnt =0;

    for(int i =0; i<n; i++){
      if(!visited[i]){
        dfs(i);
        cnt++;
      }
    }
    cout<<cnt;
    return 0;
}