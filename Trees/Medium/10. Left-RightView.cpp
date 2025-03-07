#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);
    vector<int> result;
    if (!root) return result;

    while ( !q.empty() ) {
        int n = q.size();
        vector<int> temp;
        while( n-- ) {
            auto node = q.front();
            temp.push_back(node->val);
            q.pop();

            if (node->left) q.push( node->left );
            if (node->right) q.push( node->right );
        }
        result.push_back(temp[temp.size() - 1]);
    }
    return result;
}