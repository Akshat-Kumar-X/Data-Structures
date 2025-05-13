#include <bits/stdc++.h>
using namespace std;


// Recursive Appraoch (All Possible Ways)
// put the last index in function from there it will calculate all possible ways until it reaches index 0

int fun(int index, int K, vector<int>& height) {
    if (index == 0) return 0; // Base condition

    int minVal = INT_MAX;
    for (int i=1; i<=K; i++) {
        if (index - i >= 0) {
            int val = fun(index - i, K, height) + abs(height[index] - height[index - i]);
            minVal = min(minVal, val);
        }
    }

    return minVal;
}

// Overlapping Sub-Problems found
// Applying Memoization

int fun(int index, int K, vector<int>& dp, vector<int>& height) {
    if (index == 0) return 0; // Base condition
    if (dp[index] != -1) return dp[index];

    int minVal = INT_MAX;
    for (int i=1; i<=K; i++) {
        if (index - i >= 0) {
            int val = fun(index - i, K, dp, height) + abs(height[index] - height[index - i]);
            minVal = min(minVal, val);
        }
    }

    return dp[index] = minVal;
}

// Bottom Up Approach
int main() {
    vector<int> height;
    int n = height.size();
    int K = 5; // given

    vector<int> dp(n, 0);
    dp[0] = 0;

    int minVal = INT_MAX;
    for (int i=1; i<n; i++) {
        for (int j=1; j<K; j++) {
            if (i - j >= 0) {
                int val = fun(i - j, K, dp, height) + abs(height[i] - height[i - j]);
                minVal = min(minVal, val);
            }
        }
        dp[i] = minVal;
    }
    return dp[n-1];
}

// Applying Space optimization
// Analyzing the pattern

int main() {
    vector<int> height;
    int n = height.size();

    int prev = 0;
    int prev2 = 0;

    for (int i=1; i<n; i++) {

        int L = prev + abs(height[i] - height[i-1]);
        int R = INT_MAX;
        if (i > 1)
            R = prev2 + abs(height[i] - height[i-2]);
        
        int curr = min(L, R);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}
