#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameterOfTree(TreeNode* root, int& diameter) {
    if (!root) return 0;
    int leftHeight = diameterOfTree(root->left, diameter);
    int rightHeight = diameterOfTree(root->right, diameter);

    diameter = max(leftHeight + rightHeight, diameter);

    return 1 + max( leftHeight, rightHeight );
}
