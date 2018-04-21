#include "LeetCode.h"

int maxArea(vector<int>& height) {
    int i=0, j=(int)height.size()-1;
    int ans = max(0, min(height[i], height[j])*(j-i));
    while(j>i){
        ans = max(ans, min(height[i], height[j])*(j-i));
        if(height[i]<height[j])
            i++;
        else
            j--;
    }
    return ans;
}

int main(){

}