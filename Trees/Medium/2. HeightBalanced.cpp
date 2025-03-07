#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int checkHeight(TreeNode* root, bool& balanced) {
    if (!root) return 0;

    int leftHeight = checkHeight(root->left, balanced);
    int rightHeight = checkHeight(root->right, balanced);

    if (abs(leftHeight - rightHeight) > 1) balanced = false;

    return 1 + max(leftHeight, rightHeight);
}
