#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0;
        int b = 1;
        int n = prices.size();

        int maxProfit = 0;
        while ( b < n ) {
            if ( prices[a] > prices[b] ) 
                a = b; 
            else
                maxProfit = max( maxProfit, prices[b] - prices[a] );
            b++;        
        }
        return maxProfit;
    }
};

// Time: O(N)
// Space: O(1)