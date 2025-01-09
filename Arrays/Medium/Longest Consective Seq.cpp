#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        unordered_map <int, int> mp;
        for (auto num: nums) {
            mp[num]++;
        }

        int maxLength = 1;
        for (auto x: mp) {
            int num = x.first + 1;
            int length = 1;
            if (mp.find(num-2) != mp.end()) continue;
            while (mp.find(num) != mp.end()) {
                length++;
                maxLength = max(maxLength, length);
                num++;
            }
        }
        return maxLength;
    }
};

// Time: O(N)
// Space O(N)