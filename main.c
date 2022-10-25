#include "queue.h"
#include <stdio.h>


int main(int argc, char **argv) {
    Point p = (Point) {0, 1, 2};
    Point p2 = (Point) {42, 43, 44};
    Point p3 = (Point) {-1, -1, -1};
    Point* popped = malloc(sizeof(Point));
    Queue* q = queue_new();
    queue_append(q, &p);
    queue_append(q, &p2);
    queue_append(q, &p3);
    printf("%d\n", ((Point*)(q->head->data))->x);
    printf("%d\n", ((Point*)(q->head->data))->y);
    printf("%d\n", ((Point*)(q->head->data))->z);
    printf("%d\n", ((Point*)(q->head->next->data))->x);
    printf("%d\n", ((Point*)(q->head->next->data))->y);
    printf("%d\n", ((Point*)(q->head->next->data))->z);
    printf("%d\n", ((Point*)(q->head->next->next->data))->x);
    printf("%d\n", ((Point*)(q->head->next->next->data))->y);
    printf("%d\n", ((Point*)(q->head->next->next->data))->z);
    printf("pop: %d\n", ((Point*) queue_pop(q))->x);
    printf("pop: %d\n", ((Point*) queue_pop(q))->x);
    printf("pop: %d\n", ((Point*) queue_pop(q))->x);
    return 0;
}
