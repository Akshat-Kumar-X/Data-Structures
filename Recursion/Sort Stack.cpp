#include <bits/stdc++.h>
using namespace std;

void pushInSortedStack(int num, stack <int>& st) {
    vector<int> temp;
    while(!st.empty() and st.top() < num) {
        temp.push_back(st.top());
        st.pop();
    }
    st.push(num);
    for (int i=temp.size()-1; i>=0; i--) {
        st.push(temp[i]);
    }
}

void pushInSortedStack(int num, stack <int>& st) { //recursively pushing element into sorted stack;
    if (st.empty() || st.top() >= num) {
        st.push(num);
        return;
    }
    int topElement = st.top();
    st.pop();
    pushInSortedStack(num, st);
    st.push(topElement);
}

void sortStack(stack <int>& st) {
    if (st.empty()) return;
    int num = st.top();
    st.pop();
    sortStack(st);
    pushInSortedStack(num, st);
}


int main() {
    stack <int> st;
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(4);

    sortStack(st);

    while(!st.empty()) {
        int num = st.top();
        st.pop();
        cout << num << " ";
    }

    return 0;
}