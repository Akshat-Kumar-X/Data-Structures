#include <bits/stdc++.h>
using namespace std;


int helper(int index, int n, string s, int result) {
    if (index == n) return result;
    
    result = result * 10 + (s[index] - '0');
    return helper(index + 1, n, s, result);
}

int stoi(string s) {
    int n = s.length();
    return helper(0, n, s, 0);
}