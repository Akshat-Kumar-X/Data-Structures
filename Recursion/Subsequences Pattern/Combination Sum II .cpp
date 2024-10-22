#include <bits/stdc++.h>
using namespace std;

void helper(int index, int sum, int target, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans) {

    if (sum == target) {
        ans.push_back(temp);
        return;
    }
    if (index == nums.size() or sum > target) return;

    for (int i=index; i<nums.size(); i++) {

        if (nums[i] == nums[i-1]) continue;
        
        temp.push_back(nums[index]);
        helper(index, sum + nums[index], target, temp, nums, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> nums, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, 0, target, temp, nums, ans);
    return ans;
} 