#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void leftBoundaryTraversal(TreeNode* root, vector<int>& leftBoundary) {
    if (!root or (!root->right and !root->left)) return;
    leftBoundary.push_back(root->val);
    if (root->left) leftBoundaryTraversal(root->left, leftBoundary);
    else leftBoundaryTraversal(root->right, leftBoundary);
}

void rightBoundaryTraversal(TreeNode* root, vector<int>& rightBoundary) {
    if (!root or (!root->right and !root->left)) return;
    rightBoundary.push_back(root->val);
    if (root->right) rightBoundaryTraversal(root->right, rightBoundary);
    else rightBoundaryTraversal(root->left, rightBoundary);
}

void bottomBoundaryTraversal(TreeNode* root, vector<int>& bottomBoundary) {
    if (!root) return;
    if (!root->left and !root->right) bottomBoundary.push_back(root->val);
    bottomBoundaryTraversal(root->left, bottomBoundary);
    bottomBoundaryTraversal(root->right, bottomBoundary);
}

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> leftBoundary, rightBoundary, bottomBoundary;

    leftBoundary.push_back(root->val);
    if (!root->left and !root->right) return leftBoundary;

    leftBoundaryTraversal(root->left, leftBoundary);
    bottomBoundaryTraversal(root, bottomBoundary);
    rightBoundaryTraversal(root->right, rightBoundary);
    
    vector<int> boundary;
    reverse(rightBoundary.begin(), rightBoundary.end());
    for (auto num : leftBoundary) boundary.push_back(num);
    for (auto num : bottomBoundary) boundary.push_back(num);
    for (auto num : rightBoundary) boundary.push_back(num);

    return boundary;
}