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
    ll q, alpha, Xa, Xb;
    cout << "Enter q, alpha, Xa, Xb: ";
    cin >> q >> alpha >> Xa >> Xb;

    ll Ya = modExpo(alpha, Xa, q);  // Alice sends Ya to Bob
    ll Yb = modExpo(alpha, Xb, q);  // Bob sends Yb to Alice

    ll keyAlice = modExpo(Yb, Xa, q);
    ll keyBob = modExpo(Ya, Xb, q);

    if(keyAlice == keyBob)
        cout << "Shared Key: " << keyAlice << endl;
    else
        cout << "Key mismatch error!" << endl;

    return 0;
}
