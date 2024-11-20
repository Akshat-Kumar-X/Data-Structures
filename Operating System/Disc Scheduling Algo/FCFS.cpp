#include <iostream>
#include <vector>
using namespace std;

int FCFS(vector<int>& requests, int head) {
    int totalSeekTime = 0;

    cout << "Seek Sequence: " << head;
    for (int i = 0; i < requests.size(); i++) {
        totalSeekTime += abs(requests[i] - head);
        head = requests[i];
        cout << " -> " << head;
    }
    cout << endl;

    return totalSeekTime;
}

int main() {
    int n, head;

    cout << "Enter the number of disk requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    int totalSeekTime = FCFS(requests, head);

    cout << "Total Seek Time: " << totalSeekTime << endl;

    return 0;
}
