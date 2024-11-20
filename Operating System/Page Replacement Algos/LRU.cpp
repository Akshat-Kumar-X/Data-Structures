#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int LRUPageReplacement(int pages[], int n, int capacity) {
    queue<int> frame;                   // Queue to store the pages in the frame
    unordered_set<int> pageSet;         // Set to quickly check if a page is in the frame
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If the page is not in the frame
        if (pageSet.find(page) == pageSet.end()) {
            pageFaults++;

            // If the frame is full, remove the least recently used page
            if (frame.size() == capacity) {
                int lru = frame.front(); // The front of the queue is the least recently used page
                frame.pop();
                pageSet.erase(lru);     // Remove the page from the set
            }
        } else {
            // If the page is already in the frame, remove it from the queue
            queue<int> tempQueue;
            while (!frame.empty()) {
                int frontPage = frame.front();
                frame.pop();
                if (frontPage != page) {
                    tempQueue.push(frontPage);
                }
            }
            frame = tempQueue;
        }

        // Add the current page to the frame
        frame.push(page);
        pageSet.insert(page); // Add the page to the set
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

    int pageFaults = LRUPageReplacement(pages, n, capacity);
    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
