#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* BuildTree(vector<int>& arr, int index) {
    if (index >= arr.size() or arr[index] == -1) 
        return nullptr;
    
    TreeNode* root = new TreeNode(arr[index]);
    root->left = BuildTree(arr, 2 * index + 1);
    root->right = BuildTree(arr, 2 * index + 2);

    return root;
}

// Time  : O(N)
// Space : O(h) h -> Height of the Tree

// Root Left Right
void preOrder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->val);
    preOrder(node->left, result);
    preOrder(node->right, result);
}

// Left Root Right
void inOrder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    inOrder(node->left, result);
    result.push_back(node->val);
    inOrder(node->right, result);
}

// Left Right Root
void postOrder(TreeNode* node, vector<int>& result) {
    if (!node) return;
    postOrder(node->left, result);
    postOrder(node->right, result);
    result.push_back(node->val);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6};  // -1 represents null nodes
    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   6
    
    TreeNode* root = BuildTree(arr, 0);

    vector<int> pre, in, post;
    
    preOrder(root, pre);
    inOrder(root, in);
    postOrder(root, post);

    cout << "Preorder: ";
    for (int val : pre) cout << val << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int val : in) cout << val << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int val : post) cout << val << " ";
    cout << endl;

    return 0;
}


