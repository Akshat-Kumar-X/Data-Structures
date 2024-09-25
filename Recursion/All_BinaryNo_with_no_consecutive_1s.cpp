#include <bits/stdc++.h>
using namespace std;

void print(string& str, char parent, int n) {
    int m = str.size();
    if (m == n) {
        cout << str << " ";
        return;
    }

    parent = (m == 0) ? '0' : str[m - 1];

    str += "0";
    print(str, parent, n);
    str.pop_back();

    if (parent != '1') {
        str += "1";
        print(str, parent, n);
        str.pop_back();
    }
    

}

int main() {
    int n = 3;
    string str = "";
    char parent = '0';
    print(str, parent, n);
    return 0;
}
