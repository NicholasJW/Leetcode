#include <iostream>
#include <string>
#include <map>

using namespace std;
class Logger{
public:
    map<string, int> next;

    Logger(){};

    bool shouldPrintMessage(int timestamp, string message){
        if(timestamp < next[message]){
            return false;
        }else{
            next[message] = timestamp + 10;
            return true;
        }
    }
};
