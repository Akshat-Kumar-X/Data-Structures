#include <iostream>
#include <vector>
using namespace std;

void singleLevelPaging(const vector<int>& logicalAddresses, int pageSize, int numFrames) {
    vector<int> pageTable(numFrames, -1); // Page table to map page numbers to frame numbers
    vector<string> memory(numFrames);    // Physical memory simulation
    int nextFrame = 0;
    int pageFaults = 0;

    cout << "\nLogical Address -> Physical Address Mapping:\n";

    for (int logicalAddress : logicalAddresses) {
        // Calculate page number and offset
        int pageNumber = logicalAddress / pageSize;
        int offset = logicalAddress % pageSize;

        // Check if the page is already in memory
        if (pageNumber >= numFrames || pageTable[pageNumber] == -1) {
            // Page fault
            cout << "Page fault for page " << pageNumber << endl;
            if (nextFrame < numFrames) {
                // Load the page into the next available frame
                pageTable[pageNumber] = nextFrame;
                memory[nextFrame] = "Page " + to_string(pageNumber);
                nextFrame++;
            } else {
                cout << "No free frames. Replacement logic not implemented." << endl;
                continue; 
            }
            pageFaults++;
        }

        // Calculate physical address
        int frameNumber = pageTable[pageNumber];
        int physicalAddress = frameNumber * pageSize + offset;

        cout << "Logical Address " << logicalAddress << " -> Physical Address " << physicalAddress << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    vector<int> logicalAddresses = {110, 240, 75, 300, 500};
    int pageSize = 100;                                      
    int numFrames = 4;                                       

    singleLevelPaging(logicalAddresses, pageSize, numFrames);

    return 0;
}
