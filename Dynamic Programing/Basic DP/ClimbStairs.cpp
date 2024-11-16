#include <bits/stdc++.h>
using namespace std;


// Recursion (Top Down approach)

int climbStairs(int n) {
    if (n <= 2) return n;
    return climbStairs(n-1) + climbStairs(n-2);
}

// Recursion + Memoization (To handle Overlaping Sub-problems)

int n;
vector<int> memo(n+1, -1);

int climbStairs(int n, vector<int>& memo) {
    if (n <= 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
}

// Memoization (Bottom Up Approach)

int climbStairs(int n) {
    vector<int> memo(n+1, -1);
    if (n <= 2) return n;

    memo[1] = 1;
    memo[2] = 2;
    for (int i=3; i<=n; i++) {
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}

// Space Optimization

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev1 = 1;
    int prev2 = 2;

    for (int i=3; i<=n; i++) {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

