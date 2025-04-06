#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm to find modular inverse
int modInverse(int a, int b) {
    int r1 = b, r2 = a;
    int t1 = 0, t2 = 1;
    
    while (r2 > 0) {
        int q = r1/r2;
        
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
    int a1, a2, a3;
    int m1, m2, m3;
    cin >> a1 >> a2 >> a3;
    cin >> m1 >> m2 >> m3;

    // Check if moduli are pairwise coprime
    if (__gcd(m1, m2) != 1 || __gcd(m1, m3) != 1 || __gcd(m2, m3) != 1) {
        cout << "NA";
        return 0;
    }

    int M = m1 * m2 * m3;

    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    int M1_inv = modInverse(M1, m1);
    int M2_inv = modInverse(M2, m2);
    int M3_inv = modInverse(M3, m3);

    int result = (M1 * M1_inv * a1 +
                  M2 * M2_inv * a2 +
                  M3 * M3_inv * a3) % M;

    cout << result << endl;
}
