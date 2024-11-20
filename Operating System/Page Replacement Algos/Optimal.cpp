#include <bits/stdc++.h>
using namespace std;

int OptimalPageReplacement(int pages[], int n, int capacity) {
    vector<int> frame;          // Stores the pages in memory
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If the page is not in memory
        if (find(frame.begin(), frame.end(), page) == frame.end()) {
            pageFaults++;

            // If the frame is full
            if (frame.size() == capacity) {
                int farthest = -1, index = -1;

                // Find the page that will not be used for the longest time
                for (int j = 0; j < frame.size(); j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) break;
                    }

                    // If the page is not used again or used farthest in the future
                    if (k > farthest) {
                        farthest = k;
                        index = j;
                    }
                }

                frame[index] = page; // Replace the optimal page
            } else {
                frame.push_back(page); // Add the page to memory
            }
        }
    }

    return pageFaults;
}

int main() {
    int n, capacity;

    cout << "Enter the number of pages: ";
    cin >> n;
    int pages[n];

    cout << "Enter the pages: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter the frame capacity: ";
    cin >> capacity;

    int pageFaults = OptimalPageReplacement(pages, n, capacity);
    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
