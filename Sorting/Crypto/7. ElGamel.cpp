#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main() {
    ll q, alpha, Xa, k, M;
    cout << "Enter q, alpha, Xa, k, Plaintext M: ";
    cin >> q >> alpha >> Xa >> k >> M;

    ll YA = modExpo(alpha, Xa, q);        // Public key component
    ll C1 = modExpo(alpha, k, q);         // First part of ciphertext
    ll K = modExpo(YA, k, q);             // Shared secret
    ll C2 = (M * K) % q;                  // Second part of ciphertext

    // Output Format Public Key and Cipher text
    cout << YA << " (" << C1 << ", " << C2 << ")" << endl;

    return 0;
}
