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


static inline size_t queue_size(Queue* q) {
    return q->size;
}

static inline bool queue_isEmpty(Queue* q) {
    return q->size == 0;
}

static Queue* queue_new() {
    Queue* q = malloc(sizeof(Queue));
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

static void queue_append(Queue* q, void* data) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (!queue_isEmpty(q)) {
        // link tail to new node, increment tail to point to new node
        q->tail->next = newnode;
        q->tail = newnode;
    } else {
        q->head = newnode;
        q->tail = newnode;
    }
    q->size++;
}

static void* queue_pop(Queue* q) {
    // data to return
    void* popped = q->head->data;
    // the previous head - we have to clear it
    Node* prevHead = q->head;
    // get current head, then increment it
    q->head = q->head->next;
    // cleanup
    free(prevHead);
    prevHead = NULL;
    q->size--;
    return popped;
}

static void queue_delete(Queue* q) {
    while (q->head != NULL) {
        Node *prev = q->head;
        q->head = q->head->next;
        if (prev->data != NULL)
            free(prev->data);
        free(prev);
    }
    free(q);
}

#endif /* QUEUE_H */
