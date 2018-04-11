#include <iostream>
#include <vector>

using namespace std;

// Exceed time limit, should use map 
bool canCross(vector<int>& stones){
    // How many step jumpping here
    vector<vector<int> > reachable;
    for(size_t i=0; i<stones.size(); i++){
        vector<int> a;
        // a.push_back(0);
        reachable.push_back(a);
    }
    reachable[0].push_back(0);

    // Trace back dp approach
    for(int i=1; i<(int)stones.size(); i++){
        for(int j=0; j<i; j++){
            int diff = stones[i] - stones[j];
            for(int k=0; k<(int)reachable[j].size(); k++){
                if(diff == reachable[j][k] || diff == reachable[j][k]-1 || diff == reachable[j][k]+1)
                    reachable[i].push_back(diff);
            }        
        }
    }

    // for(int i=0; i<(int)stones.size(); i++){
    //     for(int k=0; k<(int)reachable[i].size(); k++){

    //     }
    // }
    

    if(!reachable[reachable.size()-1].empty())
        return true;
    
    return false;
}

int main(){

}