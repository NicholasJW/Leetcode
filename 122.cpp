#include "LeetCode.h"

int maxProfit(vector<int>& prices){
    int prof=0;
    for(int i=1; i<(int)prices.size(); i++){
        prof += max(prices[i]-prices[i-1], 0);
    }
    return prof;
}