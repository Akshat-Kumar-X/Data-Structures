#include <bits/stdc++.h>
using namespace std;

void helper(int num, int sum, int lvl, vector<int>& temp, vector<vector<int>>& ans, int target, int k) {
    if (lvl > k) return;
    if (sum > target) return;
    if (sum == target and lvl == k) {
        ans.push_back(temp);
        return;
    }
    if (num == 10) return;

    for (int i=num; i<=9; i++) {
        temp.push_back(i);
        helper(i + 1, sum + i, lvl + 1, temp, ans, target, k);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(1, 0, 0, temp, ans, n, k);
    return ans;
}
