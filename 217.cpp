#include "LeetCode.h"

bool containsDuplicate(vector<int>& nums){
    sort(nums.begin(), nums.end());
    for(size_t i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1]) return true;
    }
    return false;
}

int main(){
    return 0;
}