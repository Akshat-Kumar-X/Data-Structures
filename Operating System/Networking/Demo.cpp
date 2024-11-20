#include <bits/stdc++.h>
using namespace std;

vector<int> generateHammingCode(vector<int>& data) {
    int dataBits = data.size();
    int parityBits = 0;

    while ((parityBits + dataBits + 1) > pow(2, parityBits)) 
        parityBits++;

    int totalBits = dataBits + parityBits;
    vector<int> hammingCode(totalBits, 0);
    for (int i=0, j = 0; i<totalBits; i++) {
        if (i & (i + 1))
            hammingCode[i] = data[j++];
    }

    for (int i=0; i<parityBits; i++) {
        int parityPos = pow(2, i) - 1;
        int parityVal = 0;

        for (int j=0; j<totalBits; j++) {
            if ((j + 1) & (1 << i)) {
                parityVal ^= hammingCode[j];
            }
        }
        hammingCode[parityPos] = parityVal;
    }

    return hammingCode;
}

int errorDetection(vector<int>& hammingCode) {
    int totalBits = hammingCode.size();
    int parityBits = log2(totalBits + 1);
    int errorPos = 0;

    for (int i=0; i<parityBits; i++) {
        int parityPos = pow(2, i) -1;
        int parityVal = 0;

        for (int j=0; j<totalBits; j++) {
            if ((j + 1) & (i << i)) {
                parityVal ^= hammingCode[j];
            }
        }
        if (parityVal != 0) {
            errorPos += (i << i);
        }
    }
    if (errorPos > 0 and errorPos <= totalBits) {
        hammingCode[errorPos - 1] ^= 1;
    }
    return errorPos;
}

int main () {
    cout << "Enter the number of data bits: ";
    int numDataBits; cin >> numDataBits;

    vector<int> data(numDataBits);
    cout << "Enter the data bits: ";
    for (int i = 0; i < numDataBits; i++) {
        cin >> data[i];
    }

    vector<int> hammingCode = generateHammingCode(data);

    cout << "Generated Hamming code: ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

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

    int detectedErrorPosition = errorDetection(hammingCode);

    if (errorDetection > 0) {
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