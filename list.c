/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"

    int WaitTime[8];
    int TurnTime[8];
    int burstTime[8];
    int totalwait = 0;
    int totalturn = 0;

// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));

    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}

// delete the selected task from the list
void delete(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;
    temp = *head;

    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        //printf("head is [%s] [%d] [%d] before making it next\n",(*head)->task->name, (*head)->task->priority, (*head)->task->burst);
        *head = (*head)->next;
        //task = NULL;       
        //printf("head is [%s] [%d] [%d] after making it next\n",(*head)->task->name, (*head)->task->priority, (*head)->task->burst);
    }
    else if (strcmp(task->name,temp->task->name) != 0){
        // interior or last element in the list
       // printf("hiiiiii\n");
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
           // printf("hello\n");
        }
        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;
    int i = 0;

    while (temp != NULL) {
        //printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        if (temp == head) {
            WaitTime[i] = 0;
            burstTime[i] = temp->task->burst;
            TurnTime[i] = burstTime[i];
            totalturn += TurnTime[i];
            i += 1;
          //  printf("The turnaround time is %d\n", TurnTime[i]);
        }
        else {
            burstTime[i] = temp->task->burst;
            WaitTime[i] = burstTime[i-1] + WaitTime[i-1];
            TurnTime[i] = WaitTime[i] + burstTime[i];
            totalturn += TurnTime[i];
            totalwait += WaitTime[i];
           // printf("The turn time is %d\n", TurnTime[i]);
            i += 1;
        }
        temp = temp->next;
    }
   // printf("the total turn time is %d\n", totalturn);
    totalwait = totalwait / 8;
    totalturn = totalturn / 8;
    printf("Average Wait Time: %d\n", totalwait);
    printf("Average Turnaround Time: %d\n", totalturn);
}
