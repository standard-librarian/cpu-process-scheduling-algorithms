#include <iostream>
#include <vector>
#include <queue>

#include "Process.h"

using namespace std;

struct CompareBurstTime {
    bool operator()(const Process& p1, const Process& p2) {
        return (p1.burst_time > p2.burst_time) ||
               ((p1.burst_time == p2.burst_time) && (p1.arrival_time > p2.arrival_time));
    }
};

void sjf_np(vector<Process>::const_iterator b, vector<Process>::const_iterator e, size_t n){
    vector<Process> processes(n);
    copy(b, e, processes.begin());

    int current_time = 0;
    priority_queue<Process, vector<Process>, CompareBurstTime> pq;

    int completed = 0;
    int index = 0;

    cout << "AT:CT\tPID\n";
    while (completed < n) {
        while (index < n && processes[index].arrival_time <= current_time)
            pq.push(processes[index++]);

        if (pq.empty()) {
            cout << current_time << ':' << processes[index].arrival_time << "\tNULL" << '\n';
            current_time = processes[index].arrival_time;
            continue;
        }

        Process p = pq.top();
        pq.pop();
        ++completed;
        cout <<  current_time << ':' << (current_time += p.burst_time) << '\t' <<p.process_number << '\n';
    }
}

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return (p1.priority > p2.priority) ||
               ((p1.priority == p2.priority) && (p1.arrival_time > p2.arrival_time));
    }
};

void priority_p(vector<Process>::const_iterator b, vector<Process>::const_iterator e , size_t n){
    vector<Process> processes(n);
    copy(b, e, processes.begin());
    sort(processes.begin(), processes.end());

    int current_time = 0;
    priority_queue<Process, vector<Process>, ComparePriority> pq;

    int completed = 0;
    int index = 0;

    cout << "AT:CT\tPID\n";
    while (completed < n) {
        while (processes[index].arrival_time <= current_time)
            pq.push(processes[index++]);

        if (pq.empty()) {
            cout << current_time << ':' << ++current_time << "\tNULL" << '\n';
            continue;
        }

        Process p = pq.top();
        pq.pop();

        if (--p.burst_time == 0)
            ++completed;
        else
            pq.push(p);

        cout << current_time << ':' << ++current_time << '\t' <<  p.process_number << '\n';
    }
}

void rr(vector<Process>::const_iterator b, vector<Process>::const_iterator e , size_t n, int quantum){
    vector<Process> processes(n);
    copy(b, e, processes.begin());
    sort(processes.begin(), processes.end());

    int current_time = 0;
    queue<Process> q;
    Process lastWorkedOn({-1, -1, -1, -1});

    int completed = 0;
    int index = 0;

    cout << "AT:CT\tPID\n";
    while (completed != n) {
        while (index < n && processes[index].arrival_time <= current_time)
            q.push(processes[index++]);
        if(lastWorkedOn.priority != -1)
            q.push(lastWorkedOn);

        if (q.empty()) {
            cout << current_time << ':' << processes[index].arrival_time << "\tNULL" << '\n';
            current_time = processes[index].arrival_time;
            continue;
        }

        Process p = q.front();
        q.pop();

        if (p.burst_time - quantum <= 0) {
            cout << current_time << ':' << (current_time += p.burst_time) << '\t' << p.process_number << '\n';
            ++completed;
        } else {
            cout << current_time << ':' << (current_time += quantum) << '\t' << p.process_number << '\n';
            p.burst_time -= quantum;
            lastWorkedOn = p;
        }
    }
}