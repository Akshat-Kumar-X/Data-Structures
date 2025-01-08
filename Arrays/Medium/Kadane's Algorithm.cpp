#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, pair<int, int>> maxSubArray(vector<int>& nums) {
        int maxx = INT_MIN;
        int sum = 0;
        int start = 0, tempStart = 0, end = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxx) {
                maxx = sum;
                start = tempStart;
                end = i;
            }
            if (sum < 0) {
                sum = 0;
                tempStart = i + 1; // Update the potential start of the next subarray
            }
        }
        return {maxx, {start, end}};
    }
};
