#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;

        int m = matrix.size();
        int n = matrix[0].size();

        // Identify rows and columns to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // Set rows to zero
        for (auto row : rows) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = 0;
            }
        }

        // Set columns to zero
        for (auto col : cols) {
            for (int row = 0; row < m; row++) {
                matrix[row][col] = 0;
            }
        }
    }
};

// Time: O(M * N)
// Space: O(M + N)