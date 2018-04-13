#include <iostream>

// Recursion
int dp[200][200];
double getProb(int a, int b){
    if(a<=0&&b<=0)
        return 0.5;
    if(a<=0&&b>0)
        return 1;
    if(b<=0&&a>0)
        return 0;
    if(dp[a][b]>0)
        return dp[a][b];
    dp[a][b]= 0.25*getProb(a-4, b)+0.25*getProb(a-1, b-3)+0.25*getProb(a-2, b-2)+0.25*getProb(a-3, b-1);
    return dp[a][b];
}

double soupServings(int N){
    if(N<25&&N>0)
        return 0.625;
    if(N>4800)
        return 1;
    // cout << (int)(N/25) << endl;
    int num=0;
    if(N%25==0)
        num = N/25;
    else
        num = N/25 + 1;
    return getProb(num, num);    
}

int main(){

}