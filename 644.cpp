#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* Find average with subarray lenght greater than or equal to k */
/* This is brute force algorithm, for the better binary search approach check 644bs.cpp */
double findMaxAverage(vector<int>& nums, int k){
    double ave=0;
    int sum=0;
    vector<int> w;
    for(int i=0; i<k; i++){
        w.push_back(nums[i]); 
        sum += nums[i];
    }
    ave = (double)sum/(double)k;
    double res = ave;

    int checkSum;
    for(int i=k; i<(int)nums.size(); i++){
        w.push_back(nums[i]);
        sum += nums[i];
        ave = (double)sum/(double)w.size();
        res = max(ave, res);
        checkSum = sum;
        for(int j=0; j<((int)w.size()-k); j++){
            checkSum -= w[j];
            ave = (double)checkSum/((double)w.size()-j-1);
            res = max(ave, res);
        }
        ave = (double)sum/(double)w.size();
    }
    return res;
}

int main(){
    cout << "hello world" << endl;
}
