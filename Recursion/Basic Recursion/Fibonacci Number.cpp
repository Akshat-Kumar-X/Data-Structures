#include <bits/stdc++.h>
using namespace std;

int fibonacciNumber(int num) {
    if (num <= 1) return num;

    return fibonacciNumber(num - 1) + fibonacciNumber(num - 2);
}

// 0 1 1 2 3 5 8 fib values
// 1 2 3 4 5 6 7 nth number