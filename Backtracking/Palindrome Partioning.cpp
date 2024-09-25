#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 1) return true;
        int l = 0;
        int r = n-1;
        while( l < r ) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    void helper(int index, int n, string s, vector<string>temp, vector<vector<string>>& ans) {
        if (index == n) {
            ans.push_back(temp);
            return;
        }
        for (int i=index; i<n; i++) {
            string str = s.substr(index, i-index+1);
            if (isPalindrome(str)) {
                temp.push_back(str);
                helper(i+1, n, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int index = 0;
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        helper(index, n, s, temp, ans);
        return ans;
    }
};