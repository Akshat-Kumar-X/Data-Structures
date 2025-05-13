
#include <bits/stdc++.h>
using namespace std;

// Simple Recruion Over String, taking partition or skipping (inside For loop)
// Keeping track of Index of partition

bool isPalindrome(string s) {
    int n = s.length();
    for (int i=0; i<n/2; i++) {
        if (s[i] != s[n-i-1])
            return false;
    }
    return true;
}

void helper(int index, string s, vector<string> temp, vector<vector<string>>& ans) {

    if (index == s.length()) {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i< s.length(); i++) {

        string word = s.substr(index, i - index + 1);

        if (isPalindrome(word)) {
            temp.push_back(word);
            helper(i + 1, s, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> temp;
    helper(0, s, temp, ans);
    return ans;
}
