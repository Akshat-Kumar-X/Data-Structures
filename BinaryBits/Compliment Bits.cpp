#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        string s = bitset<32>(num).to_string();
        s = s.substr(s.find('1'));
        for (auto& x: s) {
            if (x == '1') x = '0';
            else x = '1';
        }
        num = stoi(s, nullptr, 2);
        return num;
    }
};

// Example 1:

// Input: num = 5
// Output: 2
// Explanation: 
// The binary representation of 5 is 101 (no leading zero bits), 
// and its complement is 010. So you need to output 2.