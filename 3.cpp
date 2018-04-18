#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int lengthOfLongestSubstring(string s){
    if(s.size()==0){
        return 0;
    }
    int start=0, end=0;
    vector<char> window;
    int max=0;
    while(true){
        while(std::find(window.begin(), window.end(), s[end])==window.end()){
            window.push_back(s[end]);
            end++;
            if(end==s.size())
                break;
        }
        if(max<(int)window.size()){
            max = window.size();
        }
        if(end==s.size())
            break;
        start++;
        window.erase(window.begin());
    }

    return max;
}

int main(){
    
}
