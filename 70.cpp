#include "LeetCode.h"

int climbStairs(int n){
    int list[n+1];
    list[0]=1, list[1]=1;
    for(int i=2; i<n+1; n++){
        list[i] = list[i-2] + list[i-1];
    }
    return list[n];
}

int main(){
    return 0;
}