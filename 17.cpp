#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
vector<string> letterCombinations(string digits) {
    vector<string> result;
    vector<char*> map;
    strcpy(map[0], "");
    strcpy(map[1], "");
    strcpy(map[2], "abc");
    strcpy(map[3], "def");
    strcpy(map[4], "ghi");
    strcpy(map[5], "jkl");
    strcpy(map[6], "mno");
    strcpy(map[7], "pqrs");
    strcpy(map[8], "tuv");
    strcpy(map[9], "wxyz");

    for(size_t i=0; i<digits.size(); i++){
            
    }

    return result;
}

int main(){
    
}
