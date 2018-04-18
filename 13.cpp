#include <string>
#include <map>

using namespace std;
int romanToInt(string s) {
    map<char, int> syms;
    syms['M']=1000;
    syms['D']=500;
    syms['C']=100;
    syms['L']=50;
    syms['X']=10;
    syms['V']=5;
    syms['I']=1;

    int sum=syms[s.back()];
    for(int i=s.size()-2; i>=0; i--){
        if(syms[s[i]]<syms[s[i+1]])
            sum-=syms[s[i]];
        else
            sum+=syms[s[i]];
    }
    return sum;
}

int main(){
    
}
