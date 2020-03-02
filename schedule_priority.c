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

    schedule() {
        sortLinkedList(head);
        traverse(head);
    }

    void sortLinkedList(struct node *head) {
        struct node *node=NULL, *temp = NULL;
        char * tempname;
        int temppriority;
        int tempburst;
        node = head;
        int i = 10;

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
        
        printing();
    }

    void printing() {
        node = head;
        while (node != NULL) {
            printf("Running task = [%s] [%d] [%d]\n",node->task->name, node->task->priority, node->task->burst);
            node = node->next;
        }
    }
