#include <vector>
#include <string>
#include <climits>
#include <cstdint>
#include <algorithm>

using namespace std;

int maximumGap(vector<int>& nums) {
    const int n = nums.size();
    if(n<=1) return 0;
    int maxE = *max_element(nums.begin(),nums.end());
    int minE = *min_element(nums.begin(),nums.end());
    if(maxE == minE) return 0;
    double len = double(maxE-minE)/double(n-1);
    vector<int> maxA(n,INT_MIN);
    vector<int> minA(n,INT_MAX);
    for(int i=0; i<n; i++) {
        int index = (nums[i]-minE)/len;
        maxA[index] = max(maxA[index],nums[i]);
        minA[index] = min(minA[index],nums[i]);
    }
    int gap = 0, prev = maxA[0];
    for(int i=1; i<n; i++) {
        if(minA[i]==INT_MAX) continue;
        gap = max(gap,minA[i]-prev);
        prev = maxA[i];
    }
    return gap;
}
