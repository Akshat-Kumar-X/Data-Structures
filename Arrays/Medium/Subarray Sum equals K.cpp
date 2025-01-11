#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int count = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            // Check if there is a prefix sum that makes a subarray sum to k
            int target = prefixSum - k;

            if (mp.find(target) != mp.end()) {
                count += mp[target]; // Add the number of such prefix sums
            }

            // Record the current prefix sum in the map
            mp[prefixSum]++;
        }

        return count;
    }
};
