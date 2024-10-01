#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double pow(double x, long long n) { //O(N)
        if (n == 0) return 1;
        return x * pow(x, n-1);
    }

    double pow(double x, long long n) { //O(logN)
        if (n == 0) return 1;
        int y = pow(x, n/2);
        if ( n % 2 == 0 ) {
            return y * y;
        } else {
            return x * y * y;
        }
    }
    
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;     
        }
        return pow(x, N);
    }
};
