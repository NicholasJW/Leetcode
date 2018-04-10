// Not fully understand this,
// This is a example of 2-dimentional danymic programmin

#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// Private variables
int f[100][100];

int search(string& s, int l, int r){
    if(l>r)
        return 0;

    if(f[l][r]!=0)
        return f[l][r];
    
    f[l][r] = search(s, l, r-1)+1;
    for(int i=l; i<r; i++){
        if(s[i] == s[r])
            f[l][r] = min(f[l][r], search(s, l, i) + search(s, i+1, r-1));
    }
    return f[l][r];

}

int strangePrinter(string s){
    memset(f, 0, sizeof(f));
    return search(s, 0, s.size()-1);
}

int main(){
    string t1("aaba");
    string t2("acaba");
    string t3("acdcadba");
    
    cout << "aaba: " << strangePrinter(t1) << endl;
    cout << "acaba: " << strangePrinter(t2) << endl;
    cout << "acdcabda: " << strangePrinter(t3) << endl;
    // cout << "aaba: " << strangePrinter(t1) << endl;

}