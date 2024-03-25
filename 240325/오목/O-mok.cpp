#include <iostream>

using namespace std;

int board[20][20];

bool garo(int x, int y){
    bool result = true;
    int temp = board[x][y];

    if(y + 4 > 18) return false;
    for(int i =y; i<y+4; i++){
        if(board[x][i+1] != temp ){
            result =false;
            break;
        }
    }
    return result;
}

bool sero(int x, int y){
    bool result = true;
 
    int temp = board[x][y];
     if(x + 4 > 18) return false;
    for(int i =x; i<x+4; i++){
        
        if(board[i][y] != temp ){
            result =false;
            break;
        }
    }
    return result;
    
}

bool cross(int x, int y){
    bool result = true;
     if(y + 4 > 18 || x + 4 > 18) return false;
    
    for(int i =0; i<4; i++){
        int dx = x+1;
        int dy = y+1;
        
        if(board[x][y] != board[dx][dy]){
            result = false;
            break;
        }
        x +=1;
        y+=1;
    }
    return result;
}


int main() {
    bool find = false;
    for(int i =0; i<19; i++){
        for(int j =0; j<19; j++){
            cin >> board[i][j];
        }
    }
     int white =0;
    int black =0;
    int x,y;

    for(int i =0; i<19; i++){
        for(int j =0; j<19; j++){
            if(find)break;
           if(board[i][j] == 1){
            bool one = garo(i,j);
            bool two = sero(i,j);
            bool three = cross(i,j);
     
            if(one || two || three){
                black =1;
                if(one){
                    x= i; //i,j를 출력해라 .
                    y = j + 2;
                   
                }else if(two){
                  x = i+2;
                  y = j;
    
                }else{
                    x = i+2;
                    y = j+2;
                  
                }
                find = true;
                break;
              
            }
           }else if(board[i][j] == 2){
            bool one = garo(i,j);
            bool two = sero(i,j);
            bool three = cross(i,j);

          
            if(one || two || three){
                white =1;
          
                if(one){
                    x= i;
                    y = j + 2;
                }else if(two){
                    x = i+2;
                    y = j;
                   
                }else{
                    x = i+2;
                    y = j+2;
                }
                find = true;
                break;
            }
           }
        }
    }



   

    if(black){
        cout<<1<<'\n';

    cout<<x+1<<' '<<y+1;
    }else if(white){
        cout<<2<<'\n';

    cout<<x+1<<' '<<y+1;
    }else{
        cout<<0;
    }
    return 0;
}