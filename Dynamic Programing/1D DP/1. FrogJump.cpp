#include <bits/stdc++.h>
using namespace std;


// Recursive Appraoch (All Possible Ways)
// put the last index in function from there it will calculate all possible ways until it reaches index 0

int fun(int index, vector<int>& height) {
    if (index == 0) return 0; // Base condition

    // Operations we can perform:
    int left = fun(index - 1, height) + abs(height[index] - height[index - 1]);  
    int right = fun(index - 2, height) + abs(height[index] - height[index - 2]);

    return min(left, right);
}

// Overlapping Sub-Problems found
// Applying Memoization

int fun(int index, vector<int>& dp, vector<int>& height) {
    if (index <= 0) return 0;
    if (dp[index] != -1) return dp[index]; // if alreay Computed, Return Value

    int Left = fun(index - 1, dp ,height) + abs(height[index] - height[index - 1]);  
    int Right = fun(index - 2, dp, height) + abs(height[index] - height[index - 2]);
    
    return dp[index] = min(Left, Right); // Storing result
}


// Bottom Up Approach
int main() {
    vector<int> height;
    int n = height.size();

    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i=1; i<n; i++) {

        int L = dp[i-1] + abs(height[i] - height[i-1]);
        int R = INT_MAX;
        if (i > 1)
            R = dp[i-2] + abs(height[i] - height[i-2]);
        
        dp[i] = min(L, R);
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
