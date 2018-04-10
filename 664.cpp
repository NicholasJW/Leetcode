// This approach is incorrect, for correct danymic programming approach, see 664dp.cpp

#include <string>

using namespace std;

int printString(string left){
    if(left == "")
        return 0;
    
    char start=left[0];
    while(left[0] == start)
        left=left.substr(1);
    
    if(left.size()!=0)
        while(left[((int)left.size())-1]==start)
            left = left.substr(0, ((int)left.size())-1);

    return 1+printString(left);
}

int strangePrinter(string s){
    if(s=="")
        return 0;
    char start = s[0];
    return printString(s+start);
}

int main(){

}