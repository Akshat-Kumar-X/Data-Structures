#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree(vector<int> arr, int index) {
    if (index >= arr.size() or arr[index] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(arr[index]);
    root->left = BuildTree(arr, 2 * index + 1);
    root->right = BuildTree(arr, 2 * index + 2);

    return root;
}

// Time  : O(N)
// Space : O(N)

// Using Stack , pushing root into the stack and process its value then push its children 
vector<int> IterativePreOrder(TreeNode* root) {
    vector<int> result;

    stack <TreeNode*> st;
    st.push(root);

    while ( !st.empty() ) {
        TreeNode* node = st.top();
        result.push_back(node->val);
        st.pop();

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}

int main() {
    vector<int> arr = {3, 9, 20 ,-1, -1, 15, 7};

    TreeNode* root = BuildTree(arr, 0);

    vector<int> result = IterativePreOrder(root);

    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

