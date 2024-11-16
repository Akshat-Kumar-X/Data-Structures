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
    for (int i=0; i<processes; i++) {
        cout << "Enter Allocated Resources for P" << ProcessCount << ": ";
        for(int j=0; j<resources; j++) {
            cin >> allocatedResources[i][j];
        }
        cout << "Enter Needed Resources for P" << ProcessCount++ << ": ";
        for(int j=0; j<resources; j++) {
            cin >> neededResources[i][j];
        }
        
        for (int j=0; j<resources; j++) {
            remainingNeed
        }
        cout << endl;
    }


    return 0;
}
