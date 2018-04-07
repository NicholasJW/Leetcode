#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

bool check(vector<int>& nums, int k, double mid){
    double sum=0;
    for(int i=0; i<k; i++){
        sum+=nums[i]-mid;
    }
    if(sum>=0) return true;
    double preSum=0;
    double minSum=0;
    for(int i=k; i<(int)nums.size(); i++){
        sum+=nums[i] - mid;
        preSum+=nums[i-k] - mid;
        minSum=min(preSum, minSum);
        if(sum>=minSum)
            return true;
    }
    
    return false;
}

double findMaxGreatAverage(vector<int>& nums, int k){
    double max_num=INT_MIN;
    double min_num=INT_MAX; 

    for(int i:nums){
        max_num = max((double)i, max_num);
        min_num = min((double)i, min_num);
    }

    double prev=max_num;
    double mid;
    double err=INT_MAX;
    while(err>0.00001){
        mid = (max_num + min_num) * 0.5;
        if(check(nums, k, mid))
            min_num = mid;
        else
            max_num = mid;
        err = abs(mid-prev);
        prev = mid;
    }

    // cout << INT_MAX <<  endl;

    return mid;
}

int main(){
    vector<int> a;
    for(int i=0; i<10; i++){
        a.push_back(i);
    }
    cout << "Answer: " << findMaxGreatAverage(a, 3) << endl;
}
