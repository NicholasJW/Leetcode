#include "LeetCode.h"

string longestPalindrome(string s){
    int len = s.length();
    bool palin[len][len];
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            palin[i][j] = false;
        }
    }
    
    for(int i=0; i<len; i++){
        palin[i][i] = true;
    }

    for(int i=0; i<len-1; i++){
        if(s[i] == s[i+1])
            palin[i][i+1] = true;
        else
            palin[i][i+1] = false;
    }

    for(int l=3; l<=len; l++){
        for(int i=0; i<=len-l; i++){
            int j=i+l-1;
            if(palin[i+1][j-1]&&(s[i]==s[j])){
                palin[i][j] = true;
                // if(palin[i][j])
                    // cout << "check" << endl;
                // cout << "Start->" << i << "-end->" << j << endl;
            }else{
                palin[i][j] = false;
            }
        }
    }
    
    // for(int i=0; i<len; i++){
    //     for(int j=0; j<len; j++){
    //         if(palin[i][j]){
    //             cout << "1   ";
    //         }else{
    //             cout << "0   ";
    //         }
    //     }
    //     cout << endl;
    // }

    for(int l=len; l>0; l--){
        for(int i=0; i<=len-l; i++){
            int j=i+l-1;
            if(palin[i][j]){
                // cout << l << endl;
                // cout << "Start->" << i << "-end->" << j << endl;
                return s.substr(i, l);
            }
        }
    }
}
int main(){
    return 0;
}
