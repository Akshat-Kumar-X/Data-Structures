#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a or !b) return a == b;
    else if (a->val != b->val) return false;

    if (!isSameTree(a->left , b->left)) return false;
    if (!isSameTree(a->right , b->right)) return false;
    return true;
}