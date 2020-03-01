#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#define SIZE    100


    int WTime[SIZE];
    int TTime[SIZE];
    int bTime[SIZE];
    int twait = 0;
    int tturn = 0;

    struct node * node = NULL;
    struct node * head = NULL;
    struct node * tail = NULL;

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
        struct node *temp2;
        temp = head;
        temp2 = head;
        int i = 0;
        int iterations = 0;

        int number = 0;
        while (temp2 != NULL) {
           number = number + 1;
           //printf("the value in original burst is %d\n", originalBurstTimes[j]);
           temp2 = temp2->next;
       }
        
    //    while (temp != NULL) {
    //        originalBurstTimes[j] = temp->task->burst;
    //        //printf("the value in original burst is %d\n", originalBurstTimes[j]);
    //        temp = temp->next;
    //    }

        //printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);

        while (temp != NULL) {
            while (temp != NULL) {

            if (iterations == 0) {
                if (temp == head) {
                    if (temp->task->burst - 10 > 0) {
                        printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, 10);
                        //run(temp->task, 10);
                        temp->task->burst -= 10;
                        WTime[i] = 0;
                        bTime[i] = 10;
                        TTime[i] = bTime[i];
                        tturn += TTime[i];
                        temp = temp->next;
                    }
                    else {
                        WTime[i] = 0;
                        bTime[i] = temp->task->burst;
                        TTime[i] = bTime[i];
                        tturn += TTime[i];
                        delete(&head, temp->task);
                        // DELETE NODE
                    }
                i += 1;
                iterations += 1;
                }
                iterations += 1;
            }
            else {
                if (temp->task->burst - 10 > 0) {
                    printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, 10);
                        //run(temp->task, 10);
                        temp->task->burst -= 10;
                        WTime[i] = bTime[i-1] + WTime[i-1];
                        bTime[i] = 10;
                        TTime[i] = bTime[i] + WTime[i];
                        tturn += TTime[i];
                        twait += WTime[i];
                        if (temp->next == tail && tail->task->burst - 10 <= 0) {
                            printf("Running task = [%s] [%d] [%d] for %d units.\n",tail->task->name, tail->task->priority, tail->task->burst, tail->task->burst);
                            //run(tail->task, tail->task->burst);

                            temp->next = NULL;
                        }
                        temp = temp->next;
                }
                else {
                        //run(temp->task, temp->task->burst);
                        printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, temp->task->burst);
                        //temp->task->burst = 0;
                        WTime[i] = bTime[i-1] + WTime[i-1];
                        bTime[i] = temp->task->burst;
                        TTime[i] = bTime[i] + WTime[i];
                        tturn += TTime[i];
                        twait += WTime[i];
                        delete(&head, temp->task);
                        temp = temp->next;
                        // DELETE NODE
                }
                i += 1;
            }       
            //printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst); 
        }
        temp = head;
        }

    twait = twait / number;
    tturn = tturn / number;
    printf("Average Wait Time: %d\n", twait);
    printf("Average Turnaround Time: %d\n", tturn);
        

    }
        

