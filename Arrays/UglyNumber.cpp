#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        for (int i=1; i<n; i++) {
            int a = dp[p1]*2;
            int b = dp[p2]*3;
            int c = dp[p3]*5;

            dp[i] = min(a, min(b, c));
            if (dp[i] == a) p1++;
            if (dp[i] == b) p2++;
            if (dp[i] == c) p3++;
        }
        return dp[n-1];
    }
};