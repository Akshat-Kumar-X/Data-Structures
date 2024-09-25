#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int>& nums) {
    int n = nums.size();
    int pre = 1;
    int suf = 1;
    int maxx = INT_MIN;
    for (int i=0; i<n; i++) {
        if (pre == 0) pre = 1;
        if (suf == 0) suf = 1;

        pre *= nums[i];
        suf *= nums[n-i-1];
        maxx = max(maxx, max(pre, suf));
    }
    return maxx;
}

int main() {

}