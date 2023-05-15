# Process Scheduling Algorithms
This repository contains the implementation of various process scheduling algorithms in C++. These algorithms are commonly used in operating systems to manage processes and allocate system resources efficiently. The implemented algorithms are:

- First-Come, First-Served (FCFS)
- Preemptive Shortest Job First (SJF)
- Non-Preemptive Shortest Job First (SJF)
- Preemptive Priority
- Non-Preemptive Priority
- Round Robin

Each algorithm is implemented in a separate file and includes a brief explanation of the algorithm, its implementation, and a sample input and output.

# Theory
In computer operating systems, process scheduling is an essential component. Whenever a computer system has multiple processes to execute, it must decide which process to run next, and this is where process scheduling algorithms come into play.

- **FCFS**: First-Come, First-Served (FCFS) is a scheduling algorithm that schedules processes in the order that they arrive. The process that arrives first will be executed first, followed by the process that arrives next, and so on. It is a non-preemptive algorithm, which means that once a process starts running, it will continue to run until it finishes or is blocked.
- **SJF**: Shortest Job First (SJF) is a scheduling algorithm that schedules the shortest job first. This algorithm can be either *preemptive* or *non-preemptive*.
   - In **preemptive SJF**, a running process can be preempted if a shorter job arrives.
   - In **non-preemptive SJF**, the current running process will continue until it finishes, even if a shorter job arrives.
- **Priority Scheduling**: Priority scheduling is a scheduling algorithm where each process is assigned a priority. The process with the highest priority is scheduled first, followed by the process with the next highest priority, and so on. In preemptive priority scheduling, a running process can be preempted if a higher priority process arrives. In non-preemptive priority scheduling, the current running process will continue until it finishes, even if a higher priority process arrives.
- **Round Robin**: Round Robin is a scheduling algorithm that assigns a fixed time slice to each process in a cyclic way. The process that arrives first will be executed first, followed by the process that arrives next, and so on. If a process finishes its time slice, it is preempted and added to the end of the queue.

# Example for Input & Output for the Algorithms
### Input Processes
|Process ID|Arrival Time|Burst Time|Priority|
|:--------:|:----------:|:--------:|:------:|
|1|0|1|3|
|2|3|8|4|
|3|4|5|2|
|4|5|2|2|
|5|8|4|1|

### Start time: Completion time & Process ID for every algorithm.
|ST : CT|FCFS|P SJF|NP SJF|P Priority|NP Priority|Round Robin|
|:-----:|:--:|:---:|:----:|:--------:|:---------:|:---------:|
|0:1  |1    |1    |1      |1         |1          |1          |
|1:2  |IDLE |IDLE |IDLE   |IDLE      |IDLE       |IDLE       |
|2:3  |IDLE |IDLE |IDLE   |IDLE      |IDLE       |IDLE       |
|3:4  |2    |2    |2      |2         |2          |2          |
|4:5  |2    |3    |2      |3         |2          |2          |
|5:6  |2    |4    |2      |3         |2          |2          |
|6:7  |2    |4    |2      |3         |2          |3          |
|7:8  |2    |3    |2      |3         |2          |3          |
|8:9  |2    |3    |2      |5         |2          |3          |
|9:10 |2    |3    |2      |5         |2          |4          |
|10:11|2    |3    |2      |5         |2          |4          |
|11:12|3    |5    |4      |5         |5          |2          |
|12:13|3    |5    |4      |3         |5          |2          |
|13:14|3    |5    |5      |4         |5          |2          |
|14:15|3    |5    |5      |4         |5          |5          |
|15:16|3    |2    |5      |2         |3          |5          |
|16:17|4    |2    |5      |2         |3          |5          |
|17:18|4    |2    |3      |2         |3          |3          |
|18:19|5    |2    |3      |2         |3          |3          |
|19:20|5    |2    |3      |2         |3          |2          |
|20:21|5    |2    |3      |2         |4          |2          |
|21:22|5    |2    |3      |2         |4          |5          |

# Contributions
Contributions are welcome! If you notice any errors in the implementation or would like to add an additional process scheduling algorithm, feel free to create a pull request.

# License
This project is licensed under the terms of the GNU General Public License version 3.0 (GNU GPLv3). See the LICENSE file for details.

