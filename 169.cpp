#include "LeetCode.h"

int majorityElement(vector<int>& nums){
    map<int, int> dict;
    int n=nums.size();
    for(int i=0; i<n; i++){
        dict[nums[i]]++;
        if(dict[nums[i]] > n/2)
            return nums[i];
    }
    return 0;
}

int main(){
    map<int, int> test;
    cout << test[0] << endl;

    test[2] = 4;
    test[3] = 6;
    cout << "Value of 2: " << test[2] << endl;
    cout << "Value of 1: " << test[1] << endl;
}