#include "LeetCode.h"

int reverse(int x){
    if(x==0) return 0;
    int sign = abs(x)/x;
    x = abs(x);
    int ans = 0;
    while(x!=0){
        int digit = x%10;
        x = x/10;
        ans = ans*10 + digit;
    }
    ans *= sign;
    return ans;
}

int main(){

}