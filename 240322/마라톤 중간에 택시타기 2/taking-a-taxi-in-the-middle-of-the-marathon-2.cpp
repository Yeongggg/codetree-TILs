#include <iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int distance(int x1,int x2,int y1,int y2){
    return abs(x1-x2) + abs(y1-y2);
}
int main() {
    vector<pair<int,int>> v;
    int n; cin >>n;
    for(int i =0; i<n; i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }  
    int check[101];
    memset(check,0,sizeof(check));

    int min_dis = 987654321;
    int temp =0;
    for(int i =1; i<n-1; i++){
        check[i] =1;
        for(int j=0; j<n-1; j++){
        
            if(check[j+1]){
                int x1 = v[j].first;
                int y1 = v[j].second;

                int x2= v[j+2].first;
                int y2=v[j+2].second;
               
               temp += distance(x1,x2,y1,y2);
                
               j = j+1;
            }else{
                 int x1 = v[j].first;
                int y1 = v[j].second;

                int x2= v[j+1].first;
                int y2=v[j+1].second;
               temp += distance(x1,x2,y1,y2);
               
            }
          
        }
      
        check[i] =0;
        min_dis = min(min_dis, temp);
        temp =0;
    }
    cout<<min_dis;
    return 0;
}