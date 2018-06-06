#include "LeetCode.h"

vector<int> productExceptSelf(vector<int>& nums){
    int n=(int)nums.size();
    vector<int> res(n);
    vector<int> fromFirst(n);
    vector<int> fromLast(n);
    fromFirst[0] = nums[0];
    fromLast[0] = nums[n-1];

    for(int i=1; i<n; i++){
        fromFirst[i] = fromFirst[i-1] * nums[i]; 
        fromLast[i] = fromLast[i-1] * nums[n-1-i];
    }

    res[0] = fromLast[n-2];
    res[n-1] = fromFirst[n-2];
    for(int i=1; i<n-1; i++){
        res[i] = fromFirst[i-1] * fromLast[n-2-i];    
    }

    return res;
}
