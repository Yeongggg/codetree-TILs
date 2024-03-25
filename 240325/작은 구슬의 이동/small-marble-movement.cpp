#include <iostream>
using namespace std;

int dx[] ={0,-1,0,1};
int dy[] ={1,0,-1,0};
int main() {
   int n,t;
   cin>>n>>t;
   int x,y; cin>>x>>y;
  
   char state; cin>>state;
   int dir =0;

   if(state == 'L'){
    dir = 2;
   }else if(state == 'R'){
    dir =0;
   }else if( state ='U'){
    dir = 1;
   }else {
    dir = 3;
   }

   for(int i=0; i<t; i++){
    int nx = x+ dx[dir]; int ny = y+dy[dir];
    if(nx <0 || nx >n || ny <= 0 || ny >n){
        dir = (dir-2+4)%4; continue;
    }
    x += dx[dir]; y +=dy[dir];

   }
            cout<<x<<' '<<y;
    return 0;
}