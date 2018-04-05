#include <iostream>
#include <string>
#include <map>

using namespace std;
int longestPalindrome(string s){
    map<char, int> list;
    int ans=0;
    for(size_t i=0; i<s.size(); i++){
        list[s[i]] += 1;
        if(list[s[i]]%2 == 0){
            ans += 2;
        }
    }

    if(ans<(int)s.size())
        ans ++;
    return ans;
}

int main(){
    cout<< "aaaabbcccd: " << longestPalindrome("aaaabbcccd") << endl;
    cout<< "bb: " << longestPalindrome("bb") << endl;
    cout<< "a: " << longestPalindrome("a") << endl;
    cout<< "abb: " << longestPalindrome("abb") << endl;
}
