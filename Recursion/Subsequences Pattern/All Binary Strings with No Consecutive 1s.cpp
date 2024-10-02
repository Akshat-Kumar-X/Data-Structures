#include <bits/stdc++.h>
using namespace std;

void generateBinaryStrings(string s, vector<string>& nums, int k) {
    if (s.size() == k) {
        nums.push_back(s);
        return;
    }   
    // NotTake
    generateBinaryStrings(s + '0', nums, k);
    // Take 
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