#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
// Space : O(N)

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;

    queue <TreeNode*> q;
    q.push(root);

    while ( !q.empty() ) {
        vector<int> level;
        int size  = q.size();

        while ( size-- ) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    vector<int> arr = {3, 9, 20 ,-1, -1, 15, 7};

    TreeNode* root = BuildTree(arr, 0);

    vector<vector<int>> result = levelOrder(root);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}