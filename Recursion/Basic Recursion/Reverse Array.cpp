#include <bits/stdc++.h>
using namespace std;

void helper(int left, int right, vector<int>& nums) {
    if (left == right) return;
    swap(nums[left], nums[right]);
    helper(left + 1, right - 1, nums);
}

void reverseArray(vector<int>& nums) {
    int N = nums.size();
    helper(0, N-1, nums);
}