#include <bits/stdc++.h>
using namespace std;

char fwd(char ch) {
    if (ch == 'z') ch = 'a';
    else ch = ch + 1;
    return ch;
}
char bwd(char ch) {
    if (ch == 'a') ch = 'z';
    else ch = ch - 1;
    return ch;
}
int main() {
    char ch; cin >> ch;
    cout << fwd(ch) << " " << bwd(ch) << endl;
}