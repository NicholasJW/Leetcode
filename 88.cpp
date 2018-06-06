#include "LeetCode.h"


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    auto it=nums1.begin();
    int j=0;
    while(j<n&&it!=nums1.end()){
        if(*it > nums2[j]){
            nums1.insert(it, nums2[j]);
            j++;
        }
        it++;
    }
    while(j<n){
        nums1.push_back(nums2[j]);
        j++;
    }
}