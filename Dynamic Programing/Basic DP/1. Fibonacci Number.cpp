#include <bits/stdc++.h>
using namespace std;

// Recursion (Top-Down -> Breaking problem into smaller Sub-problems)
// Time: O(2^N)
// Space: O(N)
int fibo(int n) {
    if (n <= 1)
        return n;
        
    return fibo(n - 1) + fibo(n - 2);
}

// Memoization for Overlapping Sub-problems (Top-Down Approach)
// Time: O(N)
// Space: O(N)
int fibo(int n, vector<int>& memo) {
    if (n <= 1)
        return n;
    
    if (memo[n] != -1)
        return memo[n];

    return memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
}

// Tabulation (Bottom-Up Approach -> Starts with the smallest values and builds up to the solution)
int fibo(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimized (Bottom-Up Approach with Constant Space)
int fibo(int n) {
    if (n <= 1) 
        return n;

    int prev1 = 0, prev2 = 1;

    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return prev2;
}