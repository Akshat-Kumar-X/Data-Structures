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

void LRTF(vector<Process>& p) {
    int time = 0;          
    int completed = 0;    
    int n = p.size();

    for (int i = 0; i < n; ++i) {
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        int longest = -1;
        int maxRemainingTime = -1;

        for (int i = 0; i < n; ++i) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt > maxRemainingTime) {
                longest = i;
                maxRemainingTime = p[i].rt;
            }
        }

        if (longest == -1) {
            time++;
            continue;
        }

        p[longest].rt--;
        time++;

        if (p[longest].rt == 0) {
            p[longest].ct = time;
            p[longest].tat = p[longest].ct - p[longest].at;
            p[longest].wt = p[longest].tat - p[longest].bt;
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