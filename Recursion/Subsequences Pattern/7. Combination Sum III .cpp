#include <bits/stdc++.h>
using namespace std;


void helper(int index, int sum, int count,  int k, int n, vector<int> temp, vector<vector<int>>& ans) {
    if (count == k) {
        if (sum == n) ans.push_back(temp);
        return;
    }

    for (int i=index + 1; i<10; i++) {
            if (sum + i > n) break;
            temp.push_back(i);
            helper(i, sum + i, count + 1, k, n, temp, ans);
            temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, 0, 0, k, n, temp, ans);
    return ans;
}