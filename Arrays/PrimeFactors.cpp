#include <iostream>
#include <vector>
#include <cmath>

void primeFactors(int n) {
    std::vector<int> factors;

    // Check for number of 2s
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors up to sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    // Print the factors
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Prime factors of " << n << " are: ";
    primeFactors(n);

    return 0;
}
