#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    bool atInfinity = false;
};

// Modular inverse using Extended Euclidean Algorithm
ll modInverse(ll a, ll p) {
    ll t = 0, newT = 1;
    ll r = p, newR = a;

    while (newR != 0) {
        ll q = r / newR;
        tie(t, newT) = make_pair(newT, t - q * newT);
        tie(r, newR) = make_pair(newR, r - q * newR);
    }

    return (t + p) % p;
}

// Point addition
Point pointAdd(Point P, Point Q, ll a, ll p) {
    if (P.atInfinity) return Q;
    if (Q.atInfinity) return P;

    if (P.x == Q.x && (P.y + Q.y) % p == 0)
        return {0, 0, true}; // Point at infinity

    ll m;
    if (P.x == Q.x && P.y == Q.y) {
        ll num = (3 * P.x * P.x + a) % p;
        ll den = modInverse(2 * P.y, p);
        m = (num * den) % p;
    } else {
        ll num = (Q.y - P.y + p) % p;
        ll den = modInverse((Q.x - P.x + p) % p, p);
        m = (num * den) % p;
    }

    ll x3 = (m * m - P.x - Q.x + p * 2) % p;
    ll y3 = (m * (P.x - x3 + p) - P.y + p) % p;

    return {x3, y3, false};
}

// Scalar multiplication
Point scalarMultiply(Point P, ll k, ll a, ll p) {
    Point R = {0, 0, true}; // Point at infinity
    while (k > 0) {
        if (k % 2 == 1)
            R = pointAdd(R, P, a, p);
        P = pointAdd(P, P, a, p);
        k /= 2;
    }
    return R;
}

// ECC Encryption function
void eccEncrypt(
    ll p, ll a, ll b,
    Point G, ll nB,
    ll k, Point M
) {
    // Public key of Bob
    Point PB = scalarMultiply(G, nB, a, p);

    // C1 = k * G
    Point C1 = scalarMultiply(G, k, a, p);

    // C2 = M + k * PB
    Point kPB = scalarMultiply(PB, k, a, p);
    Point C2 = pointAdd(M, kPB, a, p);

    // Output
    cout << "Public Key: (" << PB.x << ", " << PB.y << ")\n";
    cout << "Ciphertext: {(" << C1.x << ", " << C1.y << "), (" << C2.x << ", " << C2.y << ")}\n";
}

int main() {
    // Test case 1 (from image)
    ll p = 67;
    Point M = {24, 26};
    ll a = 2, b = 3;
    Point G = {2, 22};
    ll nB = 4, k = 2;

    eccEncrypt(p, a, b, G, nB, k, M);

    // You can test with second test case by changing values:
    // p = 23; M = {9,7}; a = 1; b = 1; G = {3,10}; nB = 2; k = 2;

    return 0;
}
