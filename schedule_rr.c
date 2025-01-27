#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#define SIZE    100


    int WTime[SIZE];
    int wait[SIZE];
    int TTime[SIZE];
    int bTime[SIZE];
    int twait = 0;
    int tturn = 0;
    int responseTime[SIZE];

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
       

        while (temp != NULL) {
            while (temp != NULL) {

            if (iterations == 0) {
                if (temp == head) {
                    if (temp->task->burst - 10 > 0) {
                        printf("Running task = [%s] [%d] [%d] for %d units.\n",temp->task->name, temp->task->priority, temp->task->burst, 10);
                        //run(temp->task, 10);
                        temp->task->burst -= 10;
                        responseTime[i] = 0;
                        WTime[i] = 0;
                        //aveWaitTime(temp);
                        bTime[i] = 10;
                        TTime[i] = bTime[i];
                        tturn += TTime[i];
                        temp = temp->next;
                    }
                    else {
                        responseTime[i] = 0;
                        WTime[i] = 0;
                        //aveWaitTime(temp);
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
                        //aveWaitTime(temp);
                        WTime[i] = bTime[i-1] + WTime[i-1];
                        bTime[i] = 10;
                        responseTime[i] = bTime[i-1] + WTime[i-1];
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
                        //aveWaitTime(temp);
                        WTime[i] = bTime[i-1] + WTime[i-1];
                        bTime[i] = temp->task->burst;
                        responseTime[i] = bTime[i-1] + WTime[i-1];
                        TTime[i] = bTime[i] + WTime[i];
                        tturn += TTime[i];
                        twait += WTime[i];
                        temp->task->burst = 0; // MSC
                        delete(&head, temp->task);
                        temp = temp->next;
                }
                i += 1;
            }       
            //printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst); 
        }
        temp = head;
        }

    int rtime = 0;

    for (int i = 0; i < number; i++) {
        rtime += i * 10;
        //printf("the value of counter and response tme is %d %d\n", i, rtime);
    }

    rtime = rtime / number;
    twait = twait / number;
    tturn = tturn / number;
    //printf("the value of number is %d\n", number);
    printf("Average Wait Time: %d\n", twait);
    printf("Average Turnaround Time: %d\n", tturn);
    printf("Average Response Time: %d\n", rtime);
        
    }

    void aveWaitTime(struct node * task) {
        struct node * temp2 = NULL;
        temp2 = head;
        int number = 0;

        while (temp2 != NULL) {
           number = number + 1;
           //printf("the value in original burst is %d\n", originalBurstTimes[j]);
           temp2 = temp2->next;
       }
       int waitTime[number];
       struct node * temp = NULL;
       temp = head;
       int taskHasBurst[number];
       int count = 0;

       while (temp->task->name != task->task->name) { // which node number are we currently dealing with
           count += 1;
           temp = temp->next;
       }

        struct node * t1 = NULL;
       t1 = head;
       int counting = 0;
       while (t1 != NULL) {
           if (t1->task->burst <= 0) {
               taskHasBurst[counting] = 1;
           }
           else {
               taskHasBurst[counting] = 0;
           }
           t1 = t1->next;
           counting += 1;
       }

       struct node * t2 = NULL;
       for (int i = 0; i < number; i++) {
           if (i != count) {
               if (taskHasBurst[i] != 1) {
                   waitTime[i] += t2->task->burst;
               }
           }
       }
       int sum = 0;
       for (int i = 0; i < number; i++ ){
           sum = 0;
           sum += waitTime[i];
           printf("sum is %d\n", sum);
       }
       // printf("The average wait time is %d\n", sum/number);

    }
