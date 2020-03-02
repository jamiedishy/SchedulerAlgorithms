

General explanations of algorithm implementations for: FCFS, SJF, Priority, Round Robin, Priority-Round Robin 


FCFS:
To compile:
make fcfs
./fcfs <text file>

Refer to file schedule_fcfs.c for fcfs methods add() and schedule(). 
- add() places the nodes read from the input file into a linked list
- schedule() runs the tasks in the linked list and outputs the tasks by using traverse() in list.c 
- traverse() also calculates the average wait time, average response time and average turnaround time 

SJF:
To compile:
make sjf 
./sjf <text file>

Refer to file schedule_sjf.c for sjf methods add() and schedule().
- add() places the nodes read from the input file into a linked list
- schedule() invokes sortLinkedList() to sort the linked list with incrementing order according to task burst time 
- schedule() then invokes traverse() to print the sorted linked list 
- traverse() also calculates the average wait time, average response time and average turnaround time 
    

Priority:
To compile:
make priority
./priority <text file>

Refer to file schedule_priority.c for priority methods add() and schedule().
- add() places the nodes read from the input file into a linked list
- schedule() invokes sortLinkedList() to sort the linked list with incrementing order according to task priority level
- schedule() then invokes traverse() to print the sorted linked list 
- traverse() also calculates the average wait time, average response time and average turnaround time 


Round Robin:
To compile:
make rr 
./rr <text file>

Refer to schedule_priority.c for priority methods add() and schedule().
- add() places the nodes read from the input file into a linked list
- schedule() includes functionality to run tasks according to quantum number 10
- schedule() uses run() from CPU.c to output the tasks being executed
- schedule() also includes functionality to calculate the average wait time, average response time and average turnaround time 


Priority Round Robin
To compile:
make priority_rr 
./priority_rr <text file>

Refer to schedule_priority_rr.c for priority-roundrobin methods add() and schedule().
- add() places the nodes read from the input file into a linked list
- schedule() invokes sortLinkedList() to sort the linked list based on task priority number
- sortLinkedList() invokes printing() to print out the tasks being executed. If tasks have the same priority values, then rr() is invoked.
- rr() has functionality to handle tasks with the same priority levels. In this case, it runs the tasks based on Round Robin scheduling.
- schedule() also includes functionality to calculate the average wait time, average response time and average turnaround time 

