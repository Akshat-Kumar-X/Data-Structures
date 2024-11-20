#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool isValidIp(const string &ip) {
    vector<string> parts;
    stringstream ss(ip);
    string part;

    while (getline(ss, part, '.')) {
        parts.push_back(part);
    }

    if (parts.size() != 4) return false;

    for (const string &part : parts) {
        try {
            int num = stoi(part);
            if (num < 0 || num > 255) return false;
        } catch (...) {
            return false;
        }
    }
    return true;
}

bool isFirstAddress(const string &ip) {
    vector<string> parts;
    stringstream ss(ip);
    string part;

    while (getline(ss, part, '.')) {
        parts.push_back(part);
    }

    return parts.size() == 4 && parts[3] == "0";
}

void displayUsableAddresses(const string &ip) {
    vector<string> parts;
    stringstream ss(ip);
    string part;

    while (getline(ss, part, '.')) {
        parts.push_back(part);
    }

    if (parts.size() == 4) {
        cout << "Usable IP addresses in the subnet:\n";
        for (int i = 1; i <= 254; i++) {
            cout << parts[0] << "." << parts[1] << "." << parts[2] << "." << i << endl;
        }
    }
}

int main() {
    string ip;

    cout << "Enter an IP address: ";
    getline(cin, ip);

    if (isValidIp(ip)) {
        cout << "Valid IP address entered.\n";

        if (isFirstAddress(ip)) {
            cout << "This is the first address (Network address).\n";
        } else {
            cout << "This is not the first address.\n";
        }

        displayUsableAddresses(ip);
    } else {
        cout << "Invalid IP address.\n";
    }

    return 0;
}
