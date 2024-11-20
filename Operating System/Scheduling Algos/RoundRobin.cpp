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
};

void roundRobin(vector<Process>& p, int tq) {
    queue<int> rq;
    int time = 0;          
    int completed = 0;   
    int n = p.size();

    for (int i = 0; i < n; ++i) {
        p[i].rt = p[i].bt;
        if (p[i].at == 0) {
            rq.push(i);
        }
    }

    while (completed < n) {
        if (rq.empty()) {
            time++; 
            for (int i = 0; i < n; ++i) {
                if (p[i].at <= time && p[i].rt > 0) {
                    rq.push(i);
                }
            }
            continue;
        }

        int index = rq.front();
        rq.pop();

        Process& current = p[index];

        int exec_time = min(tq, current.rt);
        time += exec_time;
        current.rt -= exec_time;

        for (int i = 0; i < n; ++i) {
            if (p[i].at <= time && p[i].rt > 0 && i != index) {
                bool inQueue = false;
                queue<int> tempQueue = rq;
                while (!tempQueue.empty()) {
                    if (tempQueue.front() == i) {
                        inQueue = true;
                        break;
                    }
                    tempQueue.pop();
                }
                if (!inQueue) {
                    rq.push(i);
                }
            }
        }

        if (current.rt == 0) {
            current.ct = time;
            current.tat = time - current.at;
            current.wt = current.tat - current.bt;
            ++completed;
        } else {
            rq.push(index);
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

int main() {
    int n, quantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].at;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].bt;
    }

    cout << "Enter the time quantum: ";
    cin >> quantum;

    roundRobin(processes, quantum);

    return 0;
}
