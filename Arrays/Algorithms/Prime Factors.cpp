#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void primeFactors(int n) {
    vector<int> factors;

    // Check for odd factors up to sqrt(n)
    for (int i = 2; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 1) {
        factors.push_back(n);
    }

    // Print the factors
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << std::endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factors of " << n << " are: ";
    primeFactors(n);

    return 0;
}
