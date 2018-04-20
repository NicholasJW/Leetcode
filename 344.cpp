#include <string>
#include <iostream>

using namespace std;
string reverseString(string s){
    string newStr("");
    for(int i=s.size()-1; i>=0; i--){
        newStr+=s[i];
    }
    return newStr;
}

int main(){
    cout << "hello" << " : "<< reverseString("hello") << endl;
    cout << "why" << " : "<< reverseString("why") << endl;
}