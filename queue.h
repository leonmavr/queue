#ifndef QUEUE_H
#define QUEUE_H 

#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
	void* data;
	struct Node* next;
} Node;

typedef struct Queue {
	size_t size;
	Node* head;
	Node* tail;
} Queue;


extern inline size_t queue_size(Queue* q) {
    return q->size;
}

extern inline bool queue_isEmpty(Queue* q) {
    return (q->head == NULL) && (q->tail == NULL);
}

extern Queue* queue_new() {
    Queue* q = malloc(sizeof(Queue));
    q->size = 0;
    q->head = malloc(sizeof(Node));
    q->tail= malloc(sizeof(Node));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

extern void queue_append(Queue* q, void* data) {
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

extern void* queue_pop(Queue* q) {
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

extern void queue_delete(Queue* q) {
    while (q->head != NULL) {
        Node *prev = q->head;
        q->head = q->head->next;
        free(prev);
    }
    free(q);
}

#endif /* QUEUE_H */
