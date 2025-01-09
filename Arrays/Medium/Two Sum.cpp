#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end()) {
                return {mp[diff], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector <int> arr = {1, 2, 3, 4, 5};
    vector <int> nums = solution.twoSum(arr, 7);
    for (auto num: nums) {
        cout << num << " ";
    }
    return 0;
}

// Time & Space: O(N)