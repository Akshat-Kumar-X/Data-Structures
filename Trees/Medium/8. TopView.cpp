#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode *root) {
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while ( !q.empty() ) {
        int n = q.size();
        while ( n-- ) {
            auto node = q.front().first;
            auto pos = q.front().second;
            q.pop();
            if ( mp.find(pos) == mp.end() ) {
                mp[pos] = node->val;
            }
            
            if (node->left) q.push({node->left, pos-1});
            if (node->right) q.push({node->right, pos+1});
        }
    }
    vector<int> result;
    for (auto val: mp) {
        result.push_back(val.second);
    }
    return result;
    
}