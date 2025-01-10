#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> output;
        int topRow = 0, bottomRow = r - 1;
        int startCol = 0, endCol = c - 1;

        // Traverse the matrix in spiral order
        while (startCol <= endCol && topRow <= bottomRow) {
            
            // Traverse the top row from left to right
            for (int i = startCol; i <= endCol; i++) {
                output.push_back(matrix[topRow][i]);
            }
            topRow++;

            // Traverse the rightmost column from top to bottom
            for (int i = topRow; i <= bottomRow; i++) {
                output.push_back(matrix[i][endCol]);
            }
            endCol--;

            // Traverse the bottom row from right to left (if valid)
            if (topRow <= bottomRow) {
                for (int i = endCol; i >= startCol; i--) {
                    output.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }

            // Traverse the leftmost column from bottom to top (if valid)
            if (startCol <= endCol) {
                for (int i = bottomRow; i >= topRow; i--) {
                    output.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }

        return output;
    }
};
