#include <bits/stdc++.h>
using namespace std;

string generateParenthesis(string str, int open, int close, vector<string>& output) {
    if (!open and !close) {
        output.push_back(str);
        return;
    }
    if (close and close > open) {
        generateParenthesis(str+ ')', open, close - 1, output);
    }
    if (open) {
        generateParenthesis(str + '(', open - 1, close, output);
    }
}

int main() {
    int n = 3;
    int count = 0;
    string str = "()";
    vector<string> output;
    generateParenthesis(str, 0 - 1, 0, output);
    return 0;
}