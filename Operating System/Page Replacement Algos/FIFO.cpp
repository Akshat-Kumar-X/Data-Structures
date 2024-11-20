#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int FIFOPageReplacement(int pages[], int n, int capacity) {
    queue<int> frame;           // Queue to store the pages in memory
    unordered_set<int> pageSet; // Set to track the pages in memory for quick lookup
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If the page is not in memory
        if (pageSet.find(page) == pageSet.end()) {
            pageFaults++;

            // If the frame is full, remove the oldest page
            if (frame.size() == capacity) {
                int oldestPage = frame.front();
                frame.pop();
                pageSet.erase(oldestPage);
            }

            // Add the new page to the frame
            frame.push(page);
            pageSet.insert(page);
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

    int pageFaults = FIFOPageReplacement(pages, n, capacity);
    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}
