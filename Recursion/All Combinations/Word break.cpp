#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, string s, unordered_map<string , int>& mp) {
        if (index == s.length()) {
            return true;
        }
        string subStr;
        for (int i=index; i<s.length(); i++) {
            subStr += s[i];
            if (mp.find(subStr) != mp.end()) {
                if (solve(i + 1, s, mp)) return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int> mp;
        for (auto word: wordDict) {
            mp[word] = 1;
        }
        return solve(0, s, mp);
    }
};

// With Memoization

class Solution {
public:
    bool solve(int index, string s, unordered_map<string, int>& mp, vector<int>& memo) {
        if (index == s.length()) {
            return true;
        }
        
        if (memo[index] != -1) return memo[index];
        
        string subStr;
        for (int i = index; i < s.length(); i++) {
            subStr += s[i];
            if (mp.find(subStr) != mp.end()) {
                if (solve(i + 1, s, mp, memo)) {
                    return memo[index] = true;
                }
            }
        }
        return memo[index] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for (const auto& word : wordDict) {
            mp[word] = 1;
        }
        vector<int> memo(s.length(), -1);
        return solve(0, s, mp, memo);
    }
};
