#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map <int, vector<int>> mp;
    queue <pair<TreeNode*, int>> q;
    q.push({root, 0});

    while ( !q.empty() ) {
        int n = q.size();
        map <int, vector<int>> tempMap;
        while( n-- ) {
            auto node = q.front().first;
            auto pos = q.front().second;
            tempMap[pos].push_back(node->val);
            q.pop();

            if (node->left) q.push({ node->left, pos-1 });
            if (node->right) q.push({ node->right, pos+1 });
        }
        for (auto& data: tempMap) {
            auto pos = data.first;
            sort(data.second.begin(), data.second.end());
            for (auto value: data.second) {
                mp[pos].push_back(value);
            }
        }
    }
    vector<vector<int>> result;
    for (auto data: mp) {
        result.push_back(data.second);
    }
    return result;
}