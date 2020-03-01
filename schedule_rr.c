#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#define SIZE    100


    int WaitTime[8];
    int TurnTime[8];
    int burstTime[8];
    int totalwait = 0;
    int totalturn = 0;

    struct node * node = NULL;
    struct node * head = NULL;
    struct node * tail = NULL;
    struct node **IO_head;

    void add(char *n, int prty, int brst) {  // add the task to the scheduler's list of tasks

        node = malloc(sizeof(struct node));

        if (head == NULL ) {
            node -> task = malloc(sizeof(struct task));
            node -> task -> name = n;
            node -> task -> priority = prty;
            node -> task -> burst = brst;

            //printf("[%s] [%d] [%d]\n",node->task->name, node->task->priority, node->task->burst);
            
            
            head = node;
            tail = head;
            head -> next = NULL;
        }
        else {
            node -> task = malloc(sizeof(struct task));
            node -> task -> name = n;
            node -> task -> priority = prty;
            node -> task -> burst = brst;

            //printf("[%s] [%d] [%d]\n",node->task->name, node->task->priority, node->task->burst);


            tail -> next = node;
            tail = node;
            node -> next = NULL;
            
        }
    }

    void schedule() {

    struct node *temp;
    temp = head;
    int i = 0;
    int iterations = 0;


    while(head != NULL) {
        while (temp != NULL) {
            if (iterations == 0) {
                if (temp == head) {
                    if (temp->task->burst - 10 > 0) {
                        temp->task->burst -= 10;
                        WaitTime[i] = 0;
                        burstTime[i] = temp->task->burst;
                        TurnTime[i] = burstTime[i];
                        totalturn += TurnTime[i];
                    }
                    else {
                        WaitTime[i] = 0;
                        burstTime[i] = temp->task->burst;
                        TurnTime[i] = burstTime[i];
                        totalturn += TurnTime[i];
                        delete(&temp, temp->task);
                        // DELETE NODE
                    }
                i += 1;
                temp = temp->next;
                }
                iterations += 1;
                
            }
            else {
                if (temp->task->burst - 10 > 0) {
                        temp->task->burst -= 10;
                        burstTime[i] = temp->task->burst;
                        TurnTime[i] = burstTime[i];
                        totalturn += TurnTime[i];
                }
                else {
                        burstTime[i] = temp->task->burst;
                        TurnTime[i] = burstTime[i];
                        totalturn += TurnTime[i];
                        delete(&temp, temp->task);
                        // DELETE NODE
                    }
                WaitTime[i] = burstTime[i-1] + WaitTime[i-1];
                i += 1;  
                temp = temp->next;
            }
        }
        temp = head;
       // iterations += 1;
    }

    totalwait = totalwait / 8;
    totalturn = totalturn / 8;
    printf("Average Wait Time: %d\n", totalwait);
    printf("Average Turnaround Time: %d\n", totalturn);

    }
        
   //     printing();
    

    // void printing() {
    //     node = head;
    //     while (node != NULL) {
    //         printf("[%s] [%d] [%d]\n",node->task->name, node->task->priority, node->task->burst);
    //         node = node->next;
    //     }
    // }
