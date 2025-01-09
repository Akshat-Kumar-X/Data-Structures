#include <bits/stdc++.h>
using namespace std;

// Observation
// Algorithm
// Dry Run

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;
        for (int i=n-1; i>=1; i--) {
            if (nums[i] > nums[i-1]) {
                index = i;
                break;
            }
        }
        if (index == -1){ 
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i=n-1; i>=index; i--) {
            if (nums[i] > nums[index-1]) {
                swap(nums[i], nums[index-1]);
                break;
            }
        }
        reverse(nums.begin() + index, nums.end());
    }
};

// Time: O(N)
// Space: O(1)