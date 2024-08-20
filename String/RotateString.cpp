#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = n;
        while(m--) {
            char a = s[0];
            string b = s.substr(1, n-1);
            s = b + a;
            if (s == goal) return true;
        }
        return false;
    }
};