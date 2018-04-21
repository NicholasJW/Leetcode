#include "LeetCode.h"

    string longestCommonPrefix(vector<string>& strs) {
        string ans("");
        if(strs.size()==0)
            return ans;
        int index=0; 
        while(true){
            char cc;
            if(index<strs[0].size())
                cc=strs[0][index];
            else
                return ans;
            bool cont=true;
            for(size_t i=1; i<strs.size(); i++){
                if(index==strs[i].size()){
                    cont = false;
                    break;
                }
                if(cc!=strs[i][index]){
                    cont = false;
                    break;
                }            
            }
            if(cont==false){
                break;
            }else{
                index++;
                ans+=cc;
            }
        }
        return ans;
    }

int main(){
    vector<string> test = {
        "hello",
        "helloyoyo",
        "hellsar",
        "helzgw"
    };

    cout << longestCommonPrefix(test) << endl;
}