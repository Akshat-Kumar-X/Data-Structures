#include <bits/stdc++.h>
using namespace std;


// Key point is during "take" you dont do index + 1 cause we wanna take same element multiple times

void helper(int index, int sum, int target, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans) {
    if (index == nums.size() or sum > target) return;

    if (sum == target) {
        ans.push_back(temp);
        return;
    }

    // Take
    temp.push_back(nums[index]);
    helper(index, sum + nums[index], target, temp, nums, ans);

    // Not Take
    temp.pop_back();
    helper(index + 1, sum, target, temp, nums, ans);
}

vector<vector<int>> combinationSum(vector<int> nums, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, 0, target, temp, nums, ans);
    return ans;
} 