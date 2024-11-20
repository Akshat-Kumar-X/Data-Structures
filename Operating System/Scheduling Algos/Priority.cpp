#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;  
    int rt;   
    int wt;   
    int tat;  
    int ct;  
    int priority;
};

void prioritySchedulingPreemptive(vector<Process>& p) {
    int time = 0;          
    int completed = 0;     
    int n = p.size();

    for (int i = 0; i < n; ++i) {
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        int highestPriority = INT_MAX;
        int chosenIndex = -1;

        for (int i = 0; i < n; ++i) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].priority < highestPriority) {
                highestPriority = p[i].priority;
                chosenIndex = i;
            }
        }

        if (chosenIndex == -1) {
            time++;
            continue;
        }

        p[chosenIndex].rt--;
        time++;

        if (p[chosenIndex].rt == 0) {
            p[chosenIndex].ct = time;
            p[chosenIndex].tat = p[chosenIndex].ct - p[chosenIndex].at;
            p[chosenIndex].wt = p[chosenIndex].tat - p[chosenIndex].bt;
            completed++;
        }
    }

    displayProcesses(p);
}

void displayProcesses(const vector<Process>& processes) {
    cout << "\nPID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\tCompletion\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.priority << "\t\t"
             << p.wt << "\t" << p.tat << "\t\t" << p.ct << "\n";
    }
}

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].at;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].bt;
        cout << "Enter priority for process " << i + 1 << " (lower number = higher priority): ";
        cin >> processes[i].priority;
    }

    cout << "\n--- Priority Scheduling (Preemptive) ---\n";
    prioritySchedulingPreemptive(processes);

    return 0;
}
