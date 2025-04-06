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
    ll q, alpha, Xa, Xb, Xda, Xdb;
    cout << "Enter q, alpha, Xa, Xb, Xda, Xdb: ";
    cin >> q >> alpha >> Xa >> Xb >> Xda >> Xdb;

    ll Yda = modExpo(alpha, Xda, q); // Attacker's public key to Alice
    ll Ydb = modExpo(alpha, Xdb, q); // Attacker's public key to Bob

    ll Kda = modExpo(Yda, Xa, q);    // Key Alice computes with attacker
    ll Kdb = modExpo(Ydb, Xb, q);    // Key Bob computes with attacker

    cout << "K_DA: " << Kda << endl;
    cout << "K_DB: " << Kdb << endl;

    return 0;
}
