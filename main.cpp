#include <iostream>

#include "scheduling_algorithms.h"
#include "Process.h"

int main(){
    std::vector<Process> processes = {{1,0,1,3},
                                      {2,3,8,4},
                                      {3,4,5,2},
                                      {4,5,2,2},
                                      {5,8,4,1}};

    std::cout << "\n FCFS \n";
    fcfs(processes.cbegin(), processes.cend(), processes.size());

    std::cout << "\n SJF_NP \n";
    sjf_np(processes.cbegin(), processes.cend(), processes.size());

    std::cout << "\n SJF_P \n";
    priority_np(processes.cbegin(), processes.cend(), processes.size());

    std::cout << "\n Priority_NP \n";
    sjf_p(processes.cbegin(), processes.cend(), processes.size());

    std::cout << "\n Priority_P \n";
    priority_p(processes.cbegin(), processes.cend(), processes.size());

    std::cout << "\n Round Robin \n";
    rr(processes.cbegin(), processes.cend(), processes.size(), 3);
}