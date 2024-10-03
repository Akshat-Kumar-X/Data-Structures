#include <bits/stdc++.h>
using namespace std;


void printSequence( string s, int index, string str, vector<string>& ans) {
    if (index == str.size()) {
        ans.push_back(s);
        return;
    }
    // take
    printSequence(s + str[index], index + 1, str, ans);
    // notTake
    printSequence(s, index + 1, str, ans);
}

// POWER SET
void generateSubsequences(string str, vector<string>& ans) {
    int n = str.size();
    int powerSetSize = 1 << n; // 2^n

    // Loop over all possible combinations
    for (int i = 0; i < powerSetSize; i++) {
        string subsequence = "";
        
        // Check each bit of the integer i
        for (int j = 0; j < n; j++) {
            // If j-th bit of i is set, include str[j] in the subsequence
            if (i & (1 << j)) {
                subsequence += str[j];
            }
        }
        
        // Add the generated subsequence to the result
        ans.push_back(subsequence);
    }
}

int main() {
    vector<string> ans;
    printSequence("", 0, "abc", ans);
    for (const string& str : ans) {
        cout << str << endl;
    }
    return 0;
}