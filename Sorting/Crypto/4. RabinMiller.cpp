#include <bits/stdc++.h>
using namespace std;

int modExpo(int base, int exponent, int modulo) {
    int result = 1;
    base = base % modulo;

    while (exponent > 0) {
        if (exponent % 2 == 1) 
            result = (result * base) % modulo;

        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

bool millerTest(int num, int base) {
    if (num % base == 0) return false;

    int d = num - 1;
    int s = 0;
    while (d % 2 == 0) {
        d  /= 2;
        s++;
    }

    int x = modExpo(base, d, num);

    if (x == 1 or x == num-1) return true;

    for (int i=1; i<s; i++) {
        x = (x * x) % num;
        if (x == num-1) 
            return true;
    }
    return false;
}

bool isPrime(int num, vector<int> bases) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0) return false;

    for (int base : bases) {
        if (base >= num) continue;
        if (!millerTest(num, base))
            return false;
    }
    return true;
}

int main() {
    int num = 4033;
    vector<int> bases = {2, 3};
    cout << isPrime(num, bases) << endl;
}