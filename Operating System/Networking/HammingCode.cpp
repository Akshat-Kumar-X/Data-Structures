#include <bits/stdc++.h>
using namespace std;

// Function to generate the Hamming code
vector<int> generateHammingCode(vector<int> data) {
    int dataBits = data.size();
    int parityBits = 0;

    // Calculate the number of parity bits required
    while ((dataBits + parityBits + 1) > pow(2, parityBits)) {
        parityBits++;
    }

    int totalBits = dataBits + parityBits;
    vector<int> hammingCode(totalBits, 0);

    // Place data bits in positions that are not powers of 2
    for (int i = 0, j = 0; i < totalBits; i++) {
        if ((i + 1) & (i)) { // Not a power of 2
            hammingCode[i] = data[j];
            j++;
        }
    }

    // Calculate parity bits
    for (int i = 0; i < parityBits; i++) {
        int parityPosition = pow(2, i) - 1; // 1-indexed to 0-indexed
        int parityValue = 0;

        for (int j = 0; j < totalBits; j++) {
            if ((j + 1) & (1 << i)) { // Check if this bit is covered by the parity
                parityValue ^= hammingCode[j];
            }
        }
        hammingCode[parityPosition] = parityValue;
    }

    return hammingCode;
}

// Function to detect and correct errors
int detectAndCorrectError(vector<int>& hammingCode) {
    int totalBits = hammingCode.size();
    int parityBits = log2(totalBits + 1);
    int errorPosition = 0;

    // Check each parity bit
    for (int i = 0; i < parityBits; i++) {
        int parityPosition = pow(2, i) - 1; // 1-indexed to 0-indexed
        int parityValue = 0;

        for (int j = 0; j < totalBits; j++) {
            if ((j + 1) & (1 << i)) { // Check if this bit is covered by the parity
                parityValue ^= hammingCode[j];
            }
        }

        if (parityValue != 0) {
            errorPosition += (1 << i); // Accumulate the error position
        }
    }

    // Correct the error if found
    if (errorPosition > 0 && errorPosition <= totalBits) {
        hammingCode[errorPosition - 1] ^= 1; // Flip the bit
    }

    return errorPosition;
}

int main() {
    // Input the data bits
    cout << "Enter the number of data bits: ";
    int numDataBits;
    cin >> numDataBits;

    vector<int> data(numDataBits);
    cout << "Enter the data bits: ";
    for (int i = 0; i < numDataBits; i++) {
        cin >> data[i];
    }

    // Generate the Hamming code
    vector<int> hammingCode = generateHammingCode(data);

    cout << "Generated Hamming code: ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

    // Introduce an error (optional)
    cout << "Enter the error position (0 for no error): ";
    int errorPosition;
    cin >> errorPosition;

    if (errorPosition > 0 && errorPosition <= hammingCode.size()) {
        hammingCode[errorPosition - 1] ^= 1; // Introduce the error
    }

    cout << "Data sent with error (if any): ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

    // Detect and correct the error
    int detectedErrorPosition = detectAndCorrectError(hammingCode);

    if (detectedErrorPosition > 0) {
        cout << "Error detected and corrected at position: " << detectedErrorPosition << endl;
    } else {
        cout << "No error detected." << endl;
    }

    cout << "Corrected Hamming code: ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

    return 0;
}
