#include <iostream>

using namespace std;

// This method is recursive but run time exceeding 
int trace(int start, int end){
    if(start > end)
        return 0;

    if(start==end)
        return 1;        

    int sum=0;
    for(int k=start; k<=end; k++){
        sum += trace(start, k-1) + trace(k+1, end);
    }

    return sum;
}
// int numTrees(int n){
//     return trace(1, n);
// }

// This is the better dp way
int numTrees(int n){
    int res[n+1];
    res[0]=res[1]=1;

    for(int r=2; r<n+1; r++){
        for(int h=1; h<=r; h++){
            res[r] += res[h-1] * res[r-h];
        }
    }    

    return res[n];
}

int main(){

}