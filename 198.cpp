#include "LeetCode.h"

// dynamic programming 
int rob(vector<int>& nums){
    vector<int> res((int)nums.size());
    res[0] = nums[0];
    res[1] = max(nums[0], nums[1]);
    int cmax=nums[0];
    for(int i=2; i<(int)nums.size(); i++){
        res[i] = max(res[i-1], cmax+nums[i]);
        cmax = max(cmax, res[i-1]);
    }
    return res[(int)res.size()-1];
}

int main(){
    return 0;
}