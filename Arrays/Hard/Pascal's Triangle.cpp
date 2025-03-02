#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> output;

        for (int level = 1; level <= numRows; ++level) {

            vector<int> temp(level, 1);

            for (int i = 1; i < level - 1; ++i) {
                temp[i] = output[level - 2][i - 1] + output[level - 2][i];
            }

            output.push_back(temp);
        }
        return output;
    }
};

// Time: O(N^2);
// Space: O(N^2);
