#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool isNeighbor(string beginWord, string endWord){
    if(beginWord.size() != endWord.size())
        return false;
    int diff = 0;
    for(size_t i=0; i<beginWord.size(); i++){
        if(beginWord[i] != endWord[i])
            diff ++;
        if(diff > 1)
            return false;
    }
    return true;
}

void addNeighbors(string word, vector<string>& list, queue<string>& qu){
    if(list.size() == 0)
        return;
    for(size_t i=0; i<list.size(); i++){
        if(isNeighbor(word, list[i])){
            string t = list[i];
            qu.push(t);
            list.erase(remove(list.begin(), list.end(), t), list.end());
            i--;
        }
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    // Remove begin word;
    wordList.erase(remove(wordList.begin(), wordList.end(), beginWord), wordList.end());
    if(beginWord == endWord)
        return 1;

    queue<string> neighbors;
    addNeighbors(beginWord, wordList, neighbors);
    string cur;
    int dist = 2;
    while(!neighbors.empty()){
        int siz = (int) neighbors.size();
        for(int i=0; i<siz; i++){
            cur = neighbors.front();
            neighbors.pop();
            if(cur == endWord)
                return dist;
            addNeighbors(cur, wordList, neighbors);
        }
        dist ++;
    }

    return 0;
}

int main(){
    
}
