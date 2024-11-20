#include<bits/stdc++.h>
using namespace std;

struct Process {
    int pid; 
    int at; 
    int bt;
    int rt; 
    int wt; 
    int tat;
    int ct;  
};

void SRTF(vector<Process>& p) {
    int time = 0;
    int completed = 0;
    int n = p.size();

    for (int i = 0; i < n; ++i) {
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        int shortest = -1;
        int minRemainingTime = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < minRemainingTime) {
                shortest = i;
                minRemainingTime = p[i].rt;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        p[shortest].rt--;
        time++;

        if (p[shortest].rt == 0) {
            p[shortest].ct = time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            ++completed;
        }
    }

    displayProcesses(p);
}

void displayProcesses(const vector<Process>& processes) {
    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t"
             << p.wt << "\t" << p.tat << "\t\t" << p.ct << "\n";
    }
}