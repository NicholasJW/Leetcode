#include "LeetCode.h"

string getNext(string current){
    string res = "";
    int p=0;
    while(p<(int)current.length()){
        char c=current[p];
        int n=1;
        p++;
        while(p<(int)current.length() && current[p]==c){
            n++;
            p++; 
        }
        res+='0' + n;
        res+=c;
    }
    return res;
}

string countAndSay(int n){
    vector<string> list;
    list.push_back("1");
    for(int i=1; i<n; i++){
        list.push_back(getNext(list[i-1]));
    }
    return list[list.size()-1];
}

int main(){
    return 0;
}