#include <iostream>
#include<algorithm>

using namespace std;

int count_digit(int num){
    int cnt = 0;
    while(num > 0){
        num/=10;
        cnt++;
    }
    return cnt;
}

bool check_carry(int a, int b){
    bool result = true;
    int a_digit = count_digit(a);
    int b_digit = count_digit(b);

    while(a_digit >0 || b_digit> 0){
        int temp_a = a%10;
        int temp_b = b%10;
  
        if(temp_a + temp_b >= 10){
            result = false;
            break;
        }
        a/=10;
        b/=10;

        a_digit--;
        b_digit--;
    }
    
    return result;
}

int main() {
    int arr[21];

    int n; cin>>n; 
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    
    int result =0;
    int temp = 0;

    for(int i =0; i<n; i++){
        for(int j = i+1; j<n-1; j++){
            if(check_carry(arr[i], arr[j])){
                int temp_num = arr[i] + arr[j];
                for(int k = j+1; k<n; k++){
                    if(check_carry(temp_num, arr[k])){
                        temp = temp_num + arr[k];
                        result = max(result, temp);
                        temp = 0;
                    }

                }
            }
            
        }
    }
    if(result == 0){
        cout<<-1;
    }else{
        cout<<result;
    }

    return 0;
}