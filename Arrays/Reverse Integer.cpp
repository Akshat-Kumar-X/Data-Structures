#include <iostream>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int number = 0;
        while (x != 0) {
            int Digit = x % 10;
            x /= 10;

            // Check for overflow before actually performing the operations
            if (number > INT_MAX / 10 || (number == INT_MAX / 10 && Digit > 7)) {
                return 0;
            }
            if (number < INT_MIN / 10 || (number == INT_MIN / 10 && Digit < -8)) {
                return 0; 
            }

            number = number * 10 + Digit;
        }
        return number;
    }
};

int main() {
    Solution solution;
    int x = 123;
    int result = solution.reverse(x);
    std::cout << "Reversed integer: " << result << std::endl;

    return 0;
}
