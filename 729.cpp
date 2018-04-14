#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

struct Comp{
    bool operator()(const pair<int, int>& fir, const pair<int, int>& sec){
        return fir.first<sec.first;
    }
};

class MyCalendar {
private:
    set<pair<int, int>, Comp> s;    

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = s.lower_bound({start, end});
        if(next != s.end()&&next->first<end)
            return false;
        if(next != s.begin()&&((--next)->second)>start)
            return false;
        s.insert({start, end});
        return true;
    }
};