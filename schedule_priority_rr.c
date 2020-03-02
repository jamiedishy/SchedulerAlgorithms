#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#define SIZE    100

    struct node * node = NULL;
    struct node * head = NULL;
    struct node * tail = NULL;
    struct node * hh = NULL;
    int numberNodes = 0;

    int WTime[SIZE];
    int TTime[SIZE];
    int bTime[SIZE];
    int twait = 0;
    int tturn = 0;
    int i = 0;
    int iteration = 0;

    int flag = 0;
    int count = 0;

    void add(char *n, int prty, int brst) {  // add the task to the scheduler's list of tasks
        numberNodes += 1;

        node = malloc(sizeof(struct node));

        if (head == NULL ) {
            node -> task = malloc(sizeof(struct task));
            node -> task -> name = n;
            node -> task -> priority = prty;
            node -> task -> burst = brst;
            
            hh = node;
            head = node;
            tail = head;
            head -> next = NULL;
        }
        else {
            node -> task = malloc(sizeof(struct task));
            node -> task -> name = n;
            node -> task -> priority = prty;
            node -> task -> burst = brst;

            tail -> next = node;
            tail = node;
            node -> next = NULL;
            
        }
    }

    schedule() {
        sortLinkedList(head);
    }

    void sortLinkedList(struct node *head) { // sorted by priority
        struct node *node=NULL, *temp = NULL;
        char * tempname;
        int temppriority;
        int tempburst;
        node = head;
        int i = 100;

        while (i >= 0) {
            node = head;
            while (node != NULL) {
                temp = node;
                while (temp->next != NULL) {
                    if (temp->task->priority < temp->next->task->priority) {
                        tempname = temp->task->name;
                        temppriority = temp->task->priority;
                        tempburst = temp->task->burst;

                        temp->task->name = temp->next->task->name;
                        temp->task->priority = temp->next->task->priority;
                        temp->task->burst = temp->next->task->burst;

                        temp->next->task->name = tempname;
                        temp->next->task->priority = temppriority;
                        temp->next->task->burst = tempburst;

                    }
                    temp = temp->next;
                }
                node = node->next;
            }
        i -= 1;
        }
        printing(hh);
        twait = twait / numberNodes;
        tturn = tturn / numberNodes;
        // printf("nimber of nodes is %d\n", numberNodes);
        printf("Average Wait Time: %d\n", twait);
        printf("Average Turnaround Time: %d\n", tturn);
    }

    void printing(struct node * h) {
        struct node * temp = NULL;
        temp = h;

        while (temp != NULL) {
            if (temp == tail || temp->task->priority != temp->next->task->priority) {
                count = 0;
                if (temp == head) {
                    WTime[i] = 0;
                    bTime[i] = temp->task->burst;
                    TTime[i] = bTime[i];
                    tturn += TTime[i];
                    i += 1;
          //  printf("The turnaround time is %d\n", TurnTime[i]);
                }
                else {
                    bTime[i] = temp->task->burst;
                    WTime[i] = bTime[i-1] + WTime[i-1];
                    TTime[i] = WTime[i] + bTime[i];
                    tturn += TTime[i];
                    twait += WTime[i];
                   // printf("The turn time is %d\n", TurnTime[i]);
                    i += 1;
                }
                printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, temp->task->burst);
                delete(&hh, temp->task);
                temp = temp->next;
            }
            else if (temp->task->priority == temp->next->task->priority) {  
                rr(temp, temp->task->priority);
                count += 1;
                if (flag == 1) {
                    while (count > 0) {
                        count -= 1;
                        temp = temp -> next; 
                        //printf("hi\n");
                    }
                }
                if (!temp->task->burst > 0) {
                break;
                }
            }    
        }      
    }

    void rr(struct node * t, int prty) {
        struct node * temp = NULL;
        temp = t;

        while (temp->task->priority == prty) {
            if (temp->task->burst - 10 > 0) {
                    flag = 0;
                    printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, 10);
                    if (iteration == 0 && temp->task->name == hh->task->name) {
                        WTime[i] = 0;
                        iteration += 1;
                    }
                    else {
                        WTime[i] = bTime[i-1] + WTime[i-1];
                    }
                    temp->task->burst -= 10;
                    bTime[i] = 10;
                    TTime[i] = bTime[i] + WTime[i];
                    tturn += TTime[i];
                    twait += WTime[i];
                    // if (temp->next == tail && tail->task->burst - 10 <= 0) {
                    //     //printf("Running task = [%s] [%d] [%d] for %d units.\n",tail->task->name, tail->task->priority, tail->task->burst, tail->task->burst);                
                    //     //temp->next = NULL;
                    // }
                    if (temp->next == NULL) {
                        break;
                    }
                    temp = temp->next;
            }
            else {
                    printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, temp->task->burst);
                    temp->task->burst = 0;
                    WTime[i] = bTime[i-1] + WTime[i-1];
                    bTime[i] = temp->task->burst;
                    TTime[i] = bTime[i] + WTime[i];
                    tturn += TTime[i];
                    twait += WTime[i];
                    delete(&hh, temp->task);
                    if (temp->next == NULL) {
                        break;
                    }
                    else {
                    temp = temp->next;
                    }
                    //printf("heihfljsal\n");
                    flag = 1;
            }
            i += 1;
        }
    }
