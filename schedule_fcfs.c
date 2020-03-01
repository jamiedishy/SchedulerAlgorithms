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

            printf("[%s] [%d] [%d]\n",node->task->name, node->task->priority, node->task->burst);
            
            head = node;
            tail = head;
            head -> next = NULL;
        }
        else {
            node -> task = malloc(sizeof(struct task));
            node -> task -> name = n;
            node -> task -> priority = prty;
            node -> task -> burst = brst;

            printf("[%s] [%d] [%d]\n",node->task->name, node->task->priority, node->task->burst);

            tail -> next = node;
            tail = node;
            node -> next = NULL;
            
        }
    }

    void schedule() {
       traverse(head);
    }






