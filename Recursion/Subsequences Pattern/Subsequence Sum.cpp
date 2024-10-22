#include <bits/stdc++.h>
using namespace std;

bool helper(int index, int sum, int target, vector<int>& nums) {
    if (index == nums.size()) {
        return sum == target;
    }
    if (helper(index + 1, sum + nums[index], target, nums)) return true;
    if (helper(index + 1, sum + 0, target, nums)) return true;

    return false;
}

bool subSequenceSum(vector<int>& nums, int target) {
    return helper(0, 0, target, nums);
}