#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;

    while (r2 > 0) {
        int q = r1/r2;

        int r = r1 - q * r2;
        r1 = r2; 
        r2 = r;

        int s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;
        
    }
    cout << "GCD of " << a << " and " << b << " is : " << r1 << endl;
    cout << "Multiplicative Inv of " << b <<  " in Z" << a << " is : " << t1;
}