#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int leftSum = max(0, maxPathSum(root->left, maxSum));
    int rightSum = max(0, maxPathSum(root->right, maxSum));

    maxSum = max(root->val + leftSum + rightSum, maxSum);

    return max(root->val, root->val + max(leftSum, rightSum));
}
