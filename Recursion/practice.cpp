#include <bits/stdc++.h>
using namespace std;


int foo (int num, int n) {
    if (n < 1) return 1;
    int y = foo(num, n/2);
    if (n%2 == 0) {
        return y * y;
    }
    return num * y * y;
}

int main() {
    int n = 5;
    cout << foo(5,3) << endl;
}
 