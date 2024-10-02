#include <bits/stdc++.h>
using namespace std;

void generateParenthesisHelper(string s, int open, int close, vector<string>& nums) {
    if (!open and !close) {
        nums.push_back(s);
        return;
    }
    if (open)
        generateParenthesisHelper(s + '(', open-1, close, nums);
    if (close and close > open)
        generateParenthesisHelper(s + ')', open, close-1, nums);
}

vector<string> generateParenthesis(int n) {
    int open = n;
    int close = n;
    vector<string> ans;
    generateParenthesisHelper("", open, close, ans);
    return ans;
}