#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        //trimming spaces from front
        string str = "";
        int in = 0;
        for (auto ch: s) { 
            if (ch == ' ') in++;
            else break;
        }
        s = s.substr(in);
        
        bool neg = s[0] == '-' ? true: false;
        if (neg || s[0] == '+') s = s.substr(1); 

        //gettting only numbers from front.
        str = "";
        for (auto ch: s) {
            if (ch >= '0' and ch <= '9') {
                str += ch;
            } else break;
        }
        s=str;
        
        //removing leading 0s
        int i = 0;
        for (auto ch: str) {
            if (ch == '0') i++;
            else break;
        }
        s = str.substr(i);

        int limit = INT_MAX/10;
        long long num = 0;

        for (auto ch: s) {
            if (ch >= '0' and ch <= '9') {
                if (num > limit || (num == limit and ch-'0'>7))
                    return neg? INT_MIN : INT_MAX;
                num = (num*10 + (ch - '0'));
            } else break;
        }
        
        return neg? -1*num: num;
    }
};