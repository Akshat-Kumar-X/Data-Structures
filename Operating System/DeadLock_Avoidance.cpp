#include <bits/stdc++.h>
using namespace std;


int main() {
    cout << "Enter Number of Processes: ";
    int processes; cin >> processes;

    cout << "Enter Number of Resources: ";
    int resources; cin >> resources;

    cout << endl;


    vector<int> totalResources(resources);
    char resourceName = 'A';
    for (int i=0; i<resources; i++) {
        cout << "Enter Total Number of Instances in Resource " << resourceName++ << ": ";
        cin >> totalResources[i];
    }

    cout << endl;

    int ProcessCount = 1;
    vector<vector<int>> allocatedResources(processes, vector<int>(resources));
    vector<vector<int>> neededResources(processes, vector<int>(resources));
    vector<vector<int>> remainingNeed(processes, vector<int>(resources));
    vector<int> totalAllocatedResources(resources);

    for (int i=0; i<processes; i++) {
        cout << "Enter Allocated Resources for P" << ProcessCount << ": ";
        for(int j=0; j<resources; j++) {
            cin >> allocatedResources[i][j];
            totalAllocatedResources[j] += allocatedResources[i][j];
        }
        cout << "Enter Needed Resources for P" << ProcessCount++ << ": ";
        for(int j=0; j<resources; j++) {
            cin >> neededResources[i][j];
        }
        for (int j=0; j<resources; j++) {
            int remaining = neededResources[i][j] - allocatedResources[i][j];
            remainingNeed[i][j] = remaining<0? 0 : remaining;
        }
        cout << endl;
    }
    vector<int> availableResources(resources);
    for (int i=0; i<resources; i++) {
        availableResources[i] = totalResources[i] - totalAllocatedResources[i];
        cout << availableResources[i] << " ";
    }

    vector<int> safeSequence(processes);
    vector<int> visited(processes);
    bool SafeSequenceFound = true;
    int counter = 0;
    while (counter < processes) {
        bool atleastOneRequiremntFilled = false;
        for (int i=0; i<processes; i++) {
            if (visited[i]) continue;
            bool requirementFulfulled = true;
            for (int j=0; j<resources; j++) {
                if (remainingNeed[i][j] > availableResources[j]) {
                    requirementFulfulled = false;
                }
            }
            if (requirementFulfulled) {
                for (int j=0; j<resources; j++) {
                    availableResources[j] += allocatedResources[i][j];
                    remainingNeed[i][j] = 0;
                }
                atleastOneRequiremntFilled = true;
                safeSequence[counter] = i;
                counter++;
                visited[i] = 1;
            }
        }
        if (!atleastOneRequiremntFilled) {
            SafeSequenceFound = false;
            break;
        }
    }
    if (SafeSequenceFound) {
        cout << "Safe Sequence: ";
        for (int i=0; i<processes; i++) {
            cout << "P" << safeSequence[i]+1 << " -> ";
        }
    } else {
        cout << "No Safe Sequence Found!" << endl;
    }
    return 0;
}
