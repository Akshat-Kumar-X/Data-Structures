#include<bits/stdc++.h>
using namespace std;

void pushIntoStack(int num, stack <int>& st) {
    if (st.empty()){ 
        st.push(num);
        return;
    }
    int top = st.top();
    st.pop();
    pushIntoStack(num, st);
    st.push(top);
}

void reverse(stack <int>& st) {
    if (st.empty()) return;
    int num = st.top();
    st.pop();
    reverse(st);
    pushIntoStack(num, st);
}

int main() {
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    reverse(st);

    while(!st.empty()) {
        int num = st.top();
        st.pop();
        cout << num << " ";
    }
}