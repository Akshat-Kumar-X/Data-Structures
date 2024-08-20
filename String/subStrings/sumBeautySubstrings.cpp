#include <iostream>
#include <string>
#include <climits> 
#include <algorithm> 
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};

            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                int Max = 0, Min = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        Max = max(Max, freq[k]);
                        Min = min(Min, freq[k]);
                    }
                }

                sum += (Max - Min);
            }
        }

        return sum;
    }
};

int main() {
    Solution solution;
    string s = "aabcbaa";
    int result = solution.beautySum(s);
    cout << "The sum of beauty of all substrings is: " << result << endl;
    return 0;
}
