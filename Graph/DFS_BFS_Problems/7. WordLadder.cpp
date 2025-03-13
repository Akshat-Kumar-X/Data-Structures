#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> set;
    for (auto word: wordList)
        set.insert(word);
    
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while ( !q.empty() ) {
        string word = q.front().first;
        int len = q.front().second;
        q.pop();

        string str = word;
        for (auto &ch: str) {

            for (char i='a'; i<='z'; i++) {
                
                ch = i;
                if (set.find(str) != set.end()) { 

                    q.push({str, len + 1});
                    set.erase(str);
                    if (str == endWord) return len + 1;
                }
            }
            str = word;
        }
    }
    return 0;
}