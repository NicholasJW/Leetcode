#include "LeetCode.h"

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n=(int)nums.size();
    for(int i=0; i<n-2; i++){
        if(i>0 && (nums[i]==nums[i-1])) continue;
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if((nums[i]+nums[j]+nums[k])==0){
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[k]);
                    res.push_back(ans);
                }
            }
        }
    }
    return res;
}

int main(){

}