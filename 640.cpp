#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <vector>
#include <string>

using namespace std;
string solveEquation(string equation){
    boost::char_separator<char> sep("=");
    boost::tokenizer<boost::char_separator<char> > tok(equation, sep);
    vector<string> strs;
    std::copy(tok.begin(), tok.end(), std::back_inserter<vector<string> >(strs));
    
}

int main(){
    string e1 = "x+1=2";
    string e2 = "x+4-5x=60";
    string e3 = "x=2x";
    string e4 = "x=x";
    string e5 = "x-1=x";
    cout << e1 << " Solution:  "<< solveEquation(e1) << endl;
    cout << e2 << " Solution:  "<< solveEquation(e2) << endl;
    cout << e3 << " Solution:  "<< solveEquation(e3) << endl;
    cout << e4 << " Solution:  "<< solveEquation(e4) << endl;
    cout << e5 << " Solution:  "<< solveEquation(e5) << endl;
}
