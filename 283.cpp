#include "LeetCode.h"

void moveZeroes(vector<int>& nums){
    int c=0;
    if(nums.size()<2) return;
    vector<int>::iterator it=nums.begin();
    while(it<nums.end()){
        if(*it==0){
            nums.erase(it);
            c++;
        }else{
            it++;
        }
    }
    for(int i=0; i<c; i++){
        nums.push_back(0);
    }
}
