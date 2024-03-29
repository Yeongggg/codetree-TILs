#include <iostream>
#include<vector>

using namespace std;
vector<int> v;
int cnt = 0;
int n;

bool is_beautiful(){
    int idx =0;
    int two =0, three =0, four =0;
    for(int i =0; i<n; i++){    
        if(v[i] == 2){
            two++;
        }else if(v[i] == 3){
            three ++;
        }else if(v[i] == 4){
            four++;
        }
    }
    if(two % 2 == 0 && three % 3==0  && four % 4 == 0 ){
            while(idx < n){
            int temp = v[idx];
            for(int j = idx; j<idx+temp; j++){
            if(v[j] != temp) {return false;}

        }
        idx = temp + idx;
     }
    }else{
       return false;
    }
   
    return true;
}
void make_num(int cur){
    if(cur == n+1){
        if(is_beautiful()) cnt++;
        return;
    }

    for(int i=1; i<=4; i++){
        v.push_back(i);
        make_num(cur+1);
        v.pop_back();
    }
}
int main() {
    cin>>n;
    make_num(1);
    cout<<cnt;
    return 0;
}