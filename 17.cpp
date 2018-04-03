#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Make it global for the recursive function to access

    void getSolution(vector<string>& list, int count, string str, const vector<string>& options){
        if(count == ((int)options.size()) ){
            list.push_back(str);
            return;
        }
        for(size_t i=0; i<options[count].size(); i++){
            getSolution(list, count+1, str+options[count][i], options);
        }

    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> map(10);
        map[0]= "";
        map[1]= "";
        map[2]= "abc";
        map[3]= "def";
        map[4]= "ghi";
        map[5]= "jkl";
        map[6]= "mno";
        map[7]= "pqrs";
        map[8]= "tuv";
        map[9]= "wxyz";
    
        // const char* input = digits.c_str();
        vector<string> options;
        for(size_t i=0; i< digits.size(); i++){
            options.push_back(map[(int) (digits[i] - '0')]);
        }
        
        if(((int)options.size()) != 0){
            getSolution(result, 0, "", options);
        }
            

        return result;
    }



int main(){
    const char *t = "23";
    // std::cout << string(t) << std::endl;

    vector<string> answer = letterCombinations( string(t) );
    for(size_t i=0; i<answer.size(); i++)
        std::cout << answer[i]<< std::endl;
    
}
