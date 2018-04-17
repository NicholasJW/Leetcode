#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    for(int i=0; i<(int)nums.size()-1; i++){
        for(int j=i+1; j<(int)nums.size(); j++){
            if(nums[i]+nums[j]==target){
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

vector<int> twoSumHM(vector<int>& nums, int target){
    unordered_map<int, int> map;
    vector<int> res;
    for(int i=0; i<(int)nums.size(); i++){
        int lookFor = target-nums[i];
        if(map.find(lookFor)!=map.end()){
            res.push_back(map[lookFor]);
            res.push_back(i);
            break;
        }
        map.insert({nums[i], i});
    }
    return res;
}