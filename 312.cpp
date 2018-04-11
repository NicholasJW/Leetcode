// Burst Ballons dynamic problems
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


// int get(vector<int>& list, int k){
//     int res=list[k];
//     if((k-1)!=-1)
//         res *= list[k-1];
//     if(!((k+1)>=list.size()))
//         res *= list[k+1];
    
//     return res;
// }

int maxCoins(vector<int>& nums){
    int N = nums.size();
    vector<int> numList(N+2);
    numList[0]=1;
    numList[N+1]=1;
    for(int i=1; i<=N; i++){
        numList[i] = nums[i-1];
    }

    int res[N+2][N+2];
    memset(res, 0, sizeof(res));

    // Length
    for(int k=1; k<=N; k++){
        // Start
        for(int l=1; l<=N-k+1; l++){
            // End index
            int r=l+k-1;

            int maxR = 0;
            for(int final=l; final<=r; final++){
                int cc = res[l][final-1] + res[final+1][r];
                cc += numList[l-1]*numList[final]*numList[r+1];
                maxR = max(cc, maxR);
            }
            res[l][r] = maxR;
        }
    }

    return res[1][N];
}

int main(){
    vector<int> v1 = {1, 3, 9, 9, 6};
    vector<int> v2 = {3, 3, 2, 1, 6};
    vector<int> v3 = {3, 1, 5, 8};

    cout << "{1, 3, 9, 9, 6}: " << maxCoins(v1) << endl;
    cout << "{3, 3, 2, 1, 6}: " << maxCoins(v2) << endl;
    cout << "{3, 1, 5, 8}: " << maxCoins(v3) << endl;

    return 0;
}