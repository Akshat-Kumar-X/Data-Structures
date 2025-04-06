#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modExpo(ll base, ll exponent, ll modulo) {
    ll result = 1;
    base = base % modulo;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulo;

        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

ll modInverse(ll a, ll b) {
    ll t1 = 0, t2 = 1;
    ll r1 = b, r2 = a;

    while (r2 > 0) {
        ll q = r1 / r2;
        ll r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ll t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0)
        t1 += b;

    return t1;
}

int main() {
    ll p, q, e;
    cin >> p >> q >> e;

    ll plainText;
    cin >> plainText;

    ll n = p * q;
    ll phi = (p - 1) * (q - 1);

    if (__gcd(e, phi) != 1) {
        cout << "Invalid e. It must be coprime with phi(n)." << endl;
        return 1;
    }

    ll d = modInverse(e, phi);

    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    // Encryption:
    ll cipherText = modExpo(plainText, e, n);
    cout << "Encrypted (Cipher) Text: " << cipherText << endl;

    // Decryption:
    ll decryptedText = modExpo(cipherText, d, n);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
