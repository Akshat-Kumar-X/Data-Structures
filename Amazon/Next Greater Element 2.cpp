#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    stack <int> st;

    int n = nums.size();
    vector <int> ans(n, -1);

    for (int i=n-2; i>=0; i--) {
        st.push( nums[i] );
    }

    for (int i=n-1; i>=0; i--) {
        if (!st.empty() and st.top() > nums[i]) {
            ans[i] = st.top();
        } else {
            while(!st.empty() and nums[i] >= st.top()) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
        }
        st.push(nums[i]);
    }
    return ans;
}

int main() {

}