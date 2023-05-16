#include <vector>

#include "Process.h"

#ifndef CPU_PROCESS_SCHEDULING_ALGORITHMS_SCHEDULING_ALGORITHMS_H
#define CPU_PROCESS_SCHEDULING_ALGORITHMS_SCHEDULING_ALGORITHMS_H

void fcfs(std::vector<Process>::const_iterator b, std::vector<Process>::const_iterator e, size_t n);
void sjf_np(std::vector<Process>::const_iterator b, std::vector<Process>::const_iterator e, size_t n);
void priority_np(std::vector<Process>::const_iterator b, std::vector<Process>::const_iterator e, size_t n);
void sjf_p(std::vector<Process>::const_iterator b, std::vector<Process>::const_iterator e, size_t n);
void priority_p(std::vector<Process>::const_iterator b, std::vector<Process>::const_iterator e , size_t n);
void rr(std::vector<Process>::const_iterator b, std::vector<Process>::const_iterator e , size_t n, int quantum);

#endif //CPU_PROCESS_SCHEDULING_ALGORITHMS_SCHEDULING_ALGORITHMS_H
