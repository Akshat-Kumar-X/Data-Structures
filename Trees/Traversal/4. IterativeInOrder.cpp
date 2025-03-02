#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree(vector<int> arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int index = 1;
    while (!q.empty() && index < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (index < arr.size() && arr[index] != -1) {
            node->left = new TreeNode(arr[index]);
            q.push(node->left);
        }
        index++;

        if (index < arr.size() && arr[index] != -1) {
            node->right = new TreeNode(arr[index]);
            q.push(node->right);
        }
        index++;
    }
    return root;
}

// Time: O(N);
// Space: O(N);

// Iterative Inorder Traversal
vector<int> IterativeInOrder(TreeNode* root) {
    TreeNode* node = root;
    stack<TreeNode*> st;
    vector<int> result;

    while (true) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty()) break;
            node = st.top();
            st.pop();
            result.push_back(node->val);
            node = node->right;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; 
    TreeNode* root = BuildTree(arr);
    vector<int> result = IterativeInOrder(root);

    for (auto num: result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
