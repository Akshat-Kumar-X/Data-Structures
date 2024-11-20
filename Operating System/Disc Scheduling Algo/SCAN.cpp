#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SCAN(vector<int>& requests, int head, int diskSize, string direction) {
    int totalSeekTime = 0;
    vector<int> left, right;

    // Add requests to the left and right of the head
    for (int request : requests) {
        if (request < head)
            left.push_back(request);
        else
            right.push_back(request);
    }

    // Add boundaries for the disk
    if (direction == "left")
        left.push_back(0); // Add start of the disk
    else
        right.push_back(diskSize - 1); // Add end of the disk

    // Sort the left and right vectors
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    // Serve requests in the chosen direction
    cout << "Seek Sequence: " << head;

    if (direction == "left") {
        for (int i = left.size() - 1; i >= 0; i--) {
            totalSeekTime += abs(head - left[i]);
            head = left[i];
            cout << " -> " << head;
        }
        for (int i = 0; i < right.size(); i++) {
            totalSeekTime += abs(head - right[i]);
            head = right[i];
            cout << " -> " << head;
        }
    } else {
        for (int i = 0; i < right.size(); i++) {
            totalSeekTime += abs(head - right[i]);
            head = right[i];
            cout << " -> " << head;
        }
        for (int i = left.size() - 1; i >= 0; i--) {
            totalSeekTime += abs(head - left[i]);
            head = left[i];
            cout << " -> " << head;
        }
    }
    cout << endl;

    return totalSeekTime;
}

int main() {
    int n, head, diskSize;
    string direction;

    cout << "Enter the number of disk requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    cout << "Enter the disk size: ";
    cin >> diskSize;

    cout << "Enter the direction (left/right): ";
    cin >> direction;

    int totalSeekTime = SCAN(requests, head, diskSize, direction);

    cout << "Total Seek Time: " << totalSeekTime << endl;

    return 0;
}
