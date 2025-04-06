#include <bits/stdc++.h>
using namespace std;


int modInverse(int a, int b) {
    int t1 = 0, t2 = 1;
    int r1 = b, r2 = a;

    while (r2 > 0) {
        int q = r1 / r2;
        int r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0)
        t1 += b;

    return t1;
}

int main() {
    int p, q, e;
    cin >> p >> q >> e;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Check if e and phi are coprime
    if (__gcd(e, phi) != 1) {
        cout << "Invalid e. It must be coprime with phi(n)." << endl;
        return 1;
    }

    int d = modInverse(e, phi);

    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    return 0;
}
