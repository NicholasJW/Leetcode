#include <vector>
#include <iostream>

using namespace std;

struct Pair {
    int a = 0;
    int b = 0;
};
    bool checkSubSeq(vector<int>& big, vector<int>& small){
        vector<int>::iterator it = big.begin();
        
        for(unsigned int i=0; i<small.size(); i++){
            while(*it!=small[i]){
                if(it==big.end())
                    return false;
                it++; 
            }
                it++;
        }
        
        return true;        
    }

    bool checkPair(Pair& p, vector<int>& vec){
        for(unsigned int i=0; i<vec.size(); i++){
            if(i == vec.size()-1)
                return false;
            if(vec[i] == p.a)
                if(vec[i+1] == p.b)
                    return true;
        }
        return false;
    }

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        Pair p;
        bool allEmpty = true;
        for(size_t i=0; i<seqs.size(); i++){
            if(seqs[i].size() != 0){
                allEmpty = false;
                break;
            }
        }
        for(size_t i=0; i<seqs.size(); i++){
            if(!checkSubSeq(org, seqs[i])){
                return false;
            }
        }
        for(size_t i=0; i<org.size()-1; i++){
            p.a=org[i];
            p.b=org[i+1];
            for(size_t j=0; j<seqs.size(); j++){
                if(checkPair(p, seqs[j]))
                    break;
                if(j == seqs.size()-1)
                    return false;
            }
        }
        return true;
    }
    
int main(int argc, char* argv[]){
        // Checking subseq function
        vector<int> original;
        vector<int> subseq;

        for(int i=0; i<10; i++)
            original.push_back(i);

        Pair p;
        p.a = 9;
        p.b = 0;
        cout<<checkPair(p, original)<<std::endl;
        return(0);
}
