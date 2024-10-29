#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int start, int end, const string& s) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void helper(int index, const string& s, vector<string>& temp, vector<vector<string>>& ans) {
        int n = s.length();
        if (index == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < n; i++) {
            
            if (isPalindrome(index, i, s)) {
                string prefix = s.substr(index, i - index + 1);

                temp.push_back(prefix);
                helper(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        helper(0, s, temp, ans);
        return ans;
    }
};
