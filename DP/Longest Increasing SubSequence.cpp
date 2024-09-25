#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, int parent, vector<int>& nums, vector<vector<int>>& dp) {
        if (index == nums.size()) return 0;
        if (dp[index][parent + 1] != -1) return dp[index][parent + 1];

        int notTake = helper(index + 1, parent, nums, dp);

        int take = 0;
        if (parent == -1 or nums[parent] < nums[index]) 
            take = 1 + helper(index + 1, index, nums, dp);
        
        int len = max(take, notTake);
        return dp[index][parent + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, dp);
    }
};