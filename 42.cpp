#include "LeetCode.h"

int trap(vector<int>& height){
    if(height.size()==0) return 0;
    int ans=0;
    int left=0, right=(int)height.size()-1;
    int leftMax=height[left], rightMax=height[right];
    while(left<right){
        if(height[left] < height[right]){
            if(height[left]>leftMax) leftMax = height[left];
            ans += leftMax - height[left];
            left++;
        }else{
            if(height[right]>rightMax) rightMax = height[right];
            ans += rightMax - height[right];
            right--;
        }
    }
    return ans;
}

int main(){
    return 0;
}