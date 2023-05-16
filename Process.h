#ifndef CPU_PROCESS_SCHEDULING_ALGORITHMS_PROCESS_H
#define CPU_PROCESS_SCHEDULING_ALGORITHMS_PROCESS_H

struct Process {
    int process_number,
            arrival_time,
            burst_time,
            priority;

    bool operator<(const Process& other) const {
        return this->arrival_time < other.arrival_time;
    }
};

#endif //CPU_PROCESS_SCHEDULING_ALGORITHMS_PROCESS_H
