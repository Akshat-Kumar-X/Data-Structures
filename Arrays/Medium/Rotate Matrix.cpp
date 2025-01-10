#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        // Transpose the matrix
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c / 2; j++) {
                swap(matrix[i][j], matrix[i][c - j - 1]);
            }
        }
    }
};

// Time: O(r * c)
// Space: O(1)