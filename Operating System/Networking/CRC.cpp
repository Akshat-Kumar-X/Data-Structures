#include <bits/stdc++.h>
using namespace std;

vector<int> calculateCRC(vector<int> data, vector<int> divisor) {
    int n = data.size();
    int m = divisor.size();

    data.resize(n + m - 1, 0);

    for (int i = 0; i <= data.size() - m; i++) {
        if (data[i] == 1) {
            for (int j = 0; j < m; j++) {
                data[i + j] ^= divisor[j];
            }
        }
    }

    return vector<int>(data.end() - (m - 1), data.end());
}

int main() {
    cout << "Enter the number of data bits: ";
    int dataSize;
    cin >> dataSize;

    vector<int> data(dataSize);
    cout << "Enter the data bits (0 or 1): ";
    for (int i = 0; i < dataSize; i++) {
        cin >> data[i];
    }

    cout << "Enter the number of divisor bits: ";
    int divisorSize;
    cin >> divisorSize;

    vector<int> divisor(divisorSize);
    cout << "Enter the divisor bits (0 or 1): ";
    for (int i = 0; i < divisorSize; i++) {
        cin >> divisor[i];
    }

    vector<int> remainder = calculateCRC(data, divisor);

    cout << "Remainder: ";
    for (int bit : remainder) {
        cout << bit;
    }
    cout << endl;

    // Append the remainder to the original data to form the transmitted CRC code
    vector<int> transmittedData = data;
    transmittedData.insert(transmittedData.end(), remainder.begin(), remainder.end());

    cout << "Transmitted Code: ";
    for (int bit : transmittedData) {
        cout << bit;
    }
    cout << endl;

    cout << "Enter the received code: ";
    vector<int> receivedCode(transmittedData.size());
    for (int i = 0; i < receivedCode.size(); i++) {
        cin >> receivedCode[i];
    }

    // Check for errors in the received code
    vector<int> checkRemainder = calculateCRC(receivedCode, divisor);
    bool errorDetected = false;
    for (int bit : checkRemainder) {
        if (bit == 1) {
            errorDetected = true;
            break;
        }
    }

    if (errorDetected) {
        cout << "Error detected in the received code." << endl;
    } else {
        cout << "No error detected in the received code." << endl;
    }

    return 0;
}
