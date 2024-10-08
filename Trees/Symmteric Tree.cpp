#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right) {
        if (!left or !right) {
            return left == right;
        }
        if (left->val != right->val) return false;
        
        bool leftSym = helper(left->left, right->right);
        bool rightSym = helper(left->right, right->left);
        
        return leftSym and rightSym;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
};