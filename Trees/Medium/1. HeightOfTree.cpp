#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int heightOfTree(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}
