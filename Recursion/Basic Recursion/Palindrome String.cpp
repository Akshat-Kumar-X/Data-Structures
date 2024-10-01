#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int left, int right, string s) {
    if (left >= right) return s[left] == s[right];

    if (s[left] == s[right])
        return isPalindrome(left + 1, right - 1, s);
    return false;
}

bool checkPalindrome(string s) {
    int n = s.length();
    return isPalindrome(0, n-1, s);
}