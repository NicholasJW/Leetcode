#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double findMaxAverage(vector<int>& nums, int k){
    int size = (int) nums.size();
    
    int sum = 0;
    for(int i=0; i<k; i++){
        sum+=nums[i];
    }

    int ans = sum;
    for(int i=k; i<size; i++){
        sum += nums[i];
        sum -= nums[i-k];
        ans = max(sum, ans);
    }

    return (double)ans/ (double)k;
}

int main(){

    vector<int> v1;
    for(int i=1; i<10; i++){
        v1.push_back(i);
    }

    cout << findMaxAverage(v1, 3) << endl;
}
