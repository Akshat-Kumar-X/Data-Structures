#include <bits/stdc++.h>
using namespace std;

// Using For loop for recursion over an Array of elements
// Key Point is Avoiding Dupliactes in same Recursion Level

void helper(int index, int sum, vector<int> temp, int& target, vector<int>& nums, vector<vector<int>>& ans) {
    if (sum == target) {
        ans.push_back(temp);
        return;
    }
    if (sum > target) return;

    for (int i = index; i < nums.size(); i++) {
        // ⚠️ Skip duplicates at the same recursion level to avoid repeating combinations
        if (i > index && nums[i] == nums[i - 1]) 
            continue;

        if (sum + nums[i] > target) 
            break;

        temp.push_back(nums[i]);
        helper(i + 1, sum + nums[i], temp, target, nums, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    helper(0, 0, temp, target, nums, ans);
    return ans;
}
