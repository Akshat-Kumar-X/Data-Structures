#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int SSTF(vector<int>& requests, int head) {
    int totalSeekTime = 0;
    vector<bool> visited(requests.size(), false);

    cout << "Seek Sequence: " << head;

    for (int i = 0; i < requests.size(); i++) {
        int shortestDistance = INT_MAX;
        int nextIndex = -1;

        // Find the closest unvisited request
        for (int j = 0; j < requests.size(); j++) {
            if (!visited[j] && abs(requests[j] - head) < shortestDistance) {
                shortestDistance = abs(requests[j] - head);
                nextIndex = j;
            }
        }

        // Move the head to the closest request
        totalSeekTime += shortestDistance;
        head = requests[nextIndex];
        visited[nextIndex] = true;

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

    int totalSeekTime = SSTF(requests, head);

    cout << "Total Seek Time: " << totalSeekTime << endl;

    return 0;
}
