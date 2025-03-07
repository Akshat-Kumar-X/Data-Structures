#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode* A, TreeNode* B) {
    if (!A or !B) return A == B;
    if (A->val != B->val) return false;
    
    if (!helper(A->left, B->right)) return false;
    if (!helper(A->right, B->left)) return false;
    return true;
}
bool isSymmetric(TreeNode* root) {
    return helper(root->left, root->right);
}