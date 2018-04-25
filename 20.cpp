#include "LeetCode.h"

bool isPair(char first, char second){
    if(first=='('&&second==')'){
        return true;
    }
    if(first=='['&&second==']'){
        return true;
    }
    if(first=='{'&&second=='}'){
        return true;
    }
    return false;
}

bool isValid(string s){
    stack<char> st;
    unordered_set<char> opens = {'(', '{', '['}; 
    for(int i=0; i<(int)s.size(); i++){
        if(opens.find(s[i])!=opens.end())
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            if(!isPair(st.top(), s[i]))
                return false;
            st.pop();
        }
    }
    if(!st.empty())
        return false;
    
    return true;
}

int main(){
    
}