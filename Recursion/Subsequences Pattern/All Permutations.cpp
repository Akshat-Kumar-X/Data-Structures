#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int index, vector<int>& temp, vector<bool>& used, vector<vector<int>>& ans, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(nums[i]);
                helper(i, temp, used, ans, nums);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false); // To track visited indices
        vector<int> temp;
        helper(0, temp, used, ans, nums);
        return ans;
    }
};
