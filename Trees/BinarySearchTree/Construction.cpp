#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function for inserting a value into the BST
    TreeNode* insertHelper(TreeNode* node, int num) {
        if (!node) return new TreeNode(num);
        if (num < node->val) 
            node->left = insertHelper(node->left, num);
        else if (num > node->val) 
            node->right = insertHelper(node->right, num);
        return node;
    }

    // Helper function for searching a value in the BST
    bool searchHelper(TreeNode* node, int val) {
        if (!node) return false;
        if (node->val == val) return true;
        return (val < node->val) ? searchHelper(node->left, val) : searchHelper(node->right, val);
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}
    BinaryTree(int x) : root(new TreeNode(x)) {}

    // Insert function
    void insert(int num) {
        root = insertHelper(root, num);
    }

    // Search function
    void search(int num) {
        cout << (searchHelper(root, num) ? "Element Found!" : "Element Not Found") << endl;
    }
};

// Driver code
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.search(5);   // Expected: Element Found!
    tree.search(20);  // Expected: Element Not Found
}
