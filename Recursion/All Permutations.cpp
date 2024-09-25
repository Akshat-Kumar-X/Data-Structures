#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int index, vector<int>& temp, unordered_map<int, int>& mp, vector<vector<int>>& ans, vector<int>& nums) {
        int n = nums.size();

        mp[index]++;
        temp.push_back(nums[index]);

        if (temp.size() == n) {
            ans.push_back(temp);
            temp.pop_back();
            mp[index]--;
            return;
        }

        for (int i=0; i<n; i++) {
            if (mp.find(i) == mp.end() or mp[i] == 0) {
                helper(i, temp, mp, ans, nums);
            }
        }
        
        temp.pop_back();
        mp[index]--;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        vector<int> temp;
        for (int i=0; i<nums.size(); i++) {
            helper(i, temp, mp, ans, nums);
        }
        return ans;
    }
};