#include <iostream>
#include<string>

using namespace std;

int main() {
    string s; cin>>s;
    int cnt = 0;
    for(int i =0; i<s.size()-3; i++){
        if(s[i] == '(' && s[i+1] =='('){
            for(int j = i+2; j<s.size()-1; j++){
                if(s[j] == ')' && s[j+1] ==')'){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}