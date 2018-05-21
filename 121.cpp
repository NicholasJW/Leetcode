#include "LeetCode.h"

int maxProfit(vector<int>& prices){
    if(prices.size()==0) return 0;
    int min=prices[0], max=min, res=0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>max){
            max = prices[i];
            res = std::max(res, max-min);
        }
        if(prices[i]<min){
            min = prices[i];
            max = min;
            res = std::max(res, max-min);
        }
    }

    return res;
}

int main(){
    return 0;
}