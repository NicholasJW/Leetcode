#include "LeetCode.h"

vector<int> plusOne(vector<int>& digits) {
    int ca=1;
    for(int i=digits.size()-1; i>=0; i--){
        int sum=digits[i]+ca;
        digits[i]=sum%10;
        ca = sum/10;
    }        
    if(ca){
        digits.insert(digits.begin(), ca);
    }
    return digits;
}

int main(){

}
