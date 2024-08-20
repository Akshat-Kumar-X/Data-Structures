#include <iostream>
#include <string>

using namespace std;

void printAllSubstrings(string s) {
    int n = s.length();
    
    // Outer loop picks the starting point
    for (int i = 0; i < n; i++) {
        // Inner loop picks the ending point
        for (int j = i; j < n; j++) {
            // Print the substring s[i...j]
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}

int main() {
    string s = "abcd";
    printAllSubstrings(s);
    return 0;
}
