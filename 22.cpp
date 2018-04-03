#include <iostream>
#include <string>
#include <vector>

using namespace std;
void getSolution(vector<string>& list, string str, int left, int right){
    if(left==0 && right==0){
        list.push_back(str);
        return;
    }
    if(left==right){
        getSolution(list, str+"(", left-1, right);
    }else if(left==0){
        getSolution(list, str+")", left, right-1);
    }else{
        getSolution(list, str+"(", left-1, right);
        getSolution(list, str+")", left, right-1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> list;
    getSolution(list, "", n, n); 
    return list;
}

int main(){

}
