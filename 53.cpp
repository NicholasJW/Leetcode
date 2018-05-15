#include "LeetCode.h"

int maxSubArray(vector<int>& nums){
    int sum=nums[0], maxSum=sum;
    for(int i=0; i<(int)nums.size(); i++){
        sum = max(sum+nums[i], nums[i]);
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int main(){
    return 0;    
}