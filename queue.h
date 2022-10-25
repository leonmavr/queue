#ifndef QUEUE_H
#define QUEUE_H 

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
	void* data;
	struct Node* next;
} Node;

typedef struct Queue {
	size_t size;
	Node* head;
	Node* tail;
} Queue;

typedef struct Point {
    int x, y, z;
} Point;


size_t queue_size(Queue* q) {
    return q->size;
}

bool queue_isEmpty(Queue* q) {
    return (q->head == NULL) && (q->tail == NULL);
}

Queue* queue_new() {
    Queue* q = malloc(sizeof(Queue));
    q->size = 0;
    q->head = malloc(sizeof(Node));
    q->tail= malloc(sizeof(Node));
    q->head = NULL;
    q->tail = NULL;
    return q;
}


void queue_append(Queue* q, void* data) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (!queue_isEmpty(q)) {
        // link tail to newnode, increment tail
        q->tail->next = newnode;    
        q->tail = newnode;
    } else {
        q->head = newnode;
        q->tail = newnode;
    }
    q->size++;
}

void* queue_pop(Queue* q) {
    void* popped = malloc(sizeof(Node));
    // the previous head - we have to clear it
    Node* prevHead = q->head;
    // get current head, then increment it
    popped = q->head->data;
    q->head = q->head->next;
    // cleanup
    free(prevHead);
    prevHead = NULL;
    q->size--;
    return popped;
}

void queue_delete(Queue* q) {
    Node* prev = q->head;
    while (q->head != NULL) {
        printf("deleting node with y = %d\n", ((Point* )(q->head->data))->x);
        prev = q->head;
        q->head = q->head->next;
        free(prev);
    }

}

#endif /* QUEUE_H */
