#include <string>
#include <string.h>
#include <iostream>
using namespace std;
int newJewelsInStones(string J, string S){
    const char *j = J.c_str(); 
    const char *s = S.c_str();
    int counter=0;
    for(size_t i=0; i<strlen(s); i++){
        for(size_t q=0; q<strlen(j); q++){
            if(s[i] == j[q]){
                counter++;
            }
        }
    }

    return counter;
}

int main(){
    std::cout<<"az and aazjjqq"<<std::endl;     
    cout<<"Number: "<<newJewelsInStones(string("az"), string("aazjjqq"))<<endln 'kana/vim-fakeclip';
}
