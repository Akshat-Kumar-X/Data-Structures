#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int index, int sum, vector<int>& temp, vector<vector<int>>& ans, vector<int> nums, int& target) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target or index == nums.size())
            return;
        
        for (int i = index; i<nums.size(); i++) {
            if (i > index and nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            helper(i+1, sum + nums[i], temp, ans, nums, target);
            temp.pop_back();
        }

        // ----Not Take----
        // temp.push_back(nums[index]);
        // helper(index + 1, sum + nums[index], temp, ans, nums, target);
        
        // ----Not Take----
        // temp.pop_back();
        // helper(index + 1, sum, temp, ans, nums, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0, index = 0;
        helper(index, sum, temp, ans, nums, target);

        return ans;
    }
};