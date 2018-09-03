#include "LeetCode.h"

int removeDuplicates(vector<int>& nums){
    auto it = nums.begin();
    int length=0;
    while(it != nums.end()){
        int cn = *it;
        length++;
        it++;
        while(*it == cn){
            if(it == nums.end())
                return length;
            nums.erase(it);
            it++;
        }
    }
    return length;
}
