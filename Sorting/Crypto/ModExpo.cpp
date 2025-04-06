#include <iostream>
using namespace std;

int modExpo(int base, int exponent, int modulo) {
    int result = 1;
    base = base % modulo;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulo;
        }

        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

// <===== Multiplicative inverse using Fermat's theorem =====>

int modInverse(int a, int mod) {
    return modExpo(a, mod - 2, mod);
}

// <===== Multiplicative inverse using Euler Phi =====>

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int modInverse(int a, int mod) {
    int phiValue = phi(mod);
    return modExpo(a, phiValue - 1, mod);
}

int main() {
    int base, exponent, modulo;
    cin >> base >> exponent >> modulo;

    cout << "Result: " << modExpo(base, exponent, modulo) << endl;


    int a, mod;
    cin >> a >> mod;

    cout << "Multiplicative Inverse: " << modInverse(a, mod) << endl;
}
