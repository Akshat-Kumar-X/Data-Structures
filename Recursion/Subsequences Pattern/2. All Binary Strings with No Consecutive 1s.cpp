#include <bits/stdc++.h>
using namespace std;

// K -> Size of String to be generated
// Time: O(2^K)
// Space: O(k)

// Generate Binary Strings of size k with No Consecutive ones:

// Simple Recurive Approach 
// Setting Base Condition: str.size == k
// Take , Not Take 1s. and set check condition on taking 1s while in recursion.

void generateBinaryStrings(string s, vector<string>& nums, int k) {
    if (s.size() == k) {
        nums.push_back(s);
        return;
    }   
    // Not Take 1
    generateBinaryStrings(s + '0', nums, k);
    // Take 1
    if (s.empty() or s.back() != '1') {
        generateBinaryStrings(s + '1', nums, k);
    }
}

int main () {
    string s = "";
    vector<string> nums;
    int k = 3;
    generateBinaryStrings(s, nums, k);
    for (const string& str : nums) {
        cout << str << endl;
    }

    return 0;
}