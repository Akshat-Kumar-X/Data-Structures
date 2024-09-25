#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        int n = strs.size();
        int m = strs[n-1].length();
        int i = 0;
        for (auto x: strs[0]) {
            if (i < m and strs[n-1][i] == x){ 
                ans += x;
                i++;
            }
            else break;
        }
        return ans;
    }
};