#include <bits/stdc++.h>
using namespace std;

// Time and Space: O(n!×n)

// Permuation
// Recursion Over all Array Elements and keeping track of which element was used before

void helper(int index, vector<int>& temp, vector<bool>& vis, vector<vector<int>>& ans, vector<int>& nums) {
    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!vis[i]) {
            vis[i] = true;
            temp.push_back(nums[i]);
            helper(i, temp, vis, ans, nums);
            temp.pop_back();
            vis[i] = false;
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

