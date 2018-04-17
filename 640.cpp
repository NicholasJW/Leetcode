#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <sstream>

using namespace std;
string boosting(string equation){
    boost::char_separator<char> sep("=");
    boost::tokenizer<boost::char_separator<char> > tok(equation, sep);
    vector<string> strs;
    using namespace boost;
    for(tokenizer<char_separator<char> >::iterator it=tok.begin(); it!=tok.end(); it++){
        strs.push_back(*it);
    }
    return strs[0];
}

    string solveEquation(string equation) {
        int n = equation.size(), sign = 1, coeff = 0, tot = 0, i = 0;
        for (int j = 0; j < n; j++) {
            if (equation[j] == '+' || equation[j] == '-') {
                if (j > i) tot += sign*stoi(equation.substr(i, j-i));
                i = j;
            }
            // corner case: x, -x, +x
            else if (equation[j] == 'x') {
                if ((i == j) || equation[j-1] == '+')
                    coeff += sign;
                else if (equation[j-1] == '-')
                    coeff -= sign;
                else 
                    coeff += sign*stoi(equation.substr(i, j-i));
                i = j+1;
            }
           // flip sign
            else if (equation[j] == '=') {
                if (j > i) tot += sign*stoi(equation.substr(i, j-i));
                sign = -1;
                i = j+1;
            }
        }
        // there may be a number in the end
        if (i < n) tot += sign*stoi(equation.substr(i));
        if (coeff == 0 && tot == 0) return "Infinite solutions";
        if (coeff == 0 && tot) return "No solution";
        int ans = -tot/coeff;
        return "x="+to_string(ans);
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
