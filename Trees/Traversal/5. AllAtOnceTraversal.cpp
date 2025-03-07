#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree( vector<int> arr) {
    queue<TreeNode*> q;

    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int index = 1;
    while( !q.empty() ) {
        auto node = q.front();
        q.pop();

        if ( index < arr.size() and arr[index] != -1) {
            node->left = new TreeNode(arr[index]);
            q.push(node->left);
        }
        index++;
        if ( index < arr.size() and arr[index] != -1) {
            node->right = new TreeNode(arr[index]);
            q.push(node->right);
        }
        index++;
    }
    return root;
}
void AllAtOnceTraversal(TreeNode* root) {
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto topPair = st.top();
        auto node = topPair.first;
        auto state = topPair.second;
        st.pop();

        if (state == 1) {
            preOrder.push_back(node->val);
            st.push({node, 2});

            if (node->left) st.push({node->left, 1});
        }
        else if (state == 2) {
            inOrder.push_back(node->val);
            st.push({node, 3});
            
            if (node->right) st.push({node->right, 1});
        }
        else {
            postOrder.push_back(node->val);
        }
    }

    cout << "PreOrder : ";
    for (auto num : preOrder) cout << num << " ";
    cout << endl;

    cout << "InOrder : ";
    for (auto num : inOrder) cout << num << " ";
    cout << endl;

    cout << "PostOrder : ";
    for (auto num : postOrder) cout << num << " ";
    cout << endl;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; 
    TreeNode* root = BuildTree(arr);
    AllAtOnceTraversal(root);
}