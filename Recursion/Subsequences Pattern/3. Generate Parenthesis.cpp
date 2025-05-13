#include <bits/stdc++.h>
using namespace std;

// Time: O(2^N)
// Space: O(N)

// Simply Keeping track of Open and close Brackets during recursive calls
// make sure open < n and close < open always during recursion
// Setting Boundary Conditions and Base Condition

void helper(int open, int close, string s, int n, vector<string>& result) {
    if (s.length() == 2 * n) {
        result.push_back(s);
        return;
    }

    if (open < n) 
        helper(open + 1, close, s + '(', n, result);

    if (close < n and close < open) 
        helper(open, close + 1, s + ')', n, result);
}
vector<string> generateParenthesis(int n) {
    int open = 0, close = 0;
    vector<string> result;
    helper(open, close, "", n, result);
    return result;
}