#include "../queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// test case index
unsigned g_indCase = 0;

#define CMP_POINTS(ptrQueueData, targetPoint) do { \
    int tx = targetPoint->x; \
    int ty = targetPoint->y; \
    int tz = targetPoint->z; \
    printf("%s (case #%d):\n\tinput 1: %d, %d, %d\n\tinput 2: %d, %d, %d\n", \
        __func__, \
        g_indCase++, \
        ((ptrQueueData))->x, \
        ((ptrQueueData))->y, \
        ((ptrQueueData))->z, \
        tx, ty, tz); \
    assert((ptrQueueData)->x == tx); \
    assert((ptrQueueData)->y == ty); \
    assert((ptrQueueData)->z == tz); \
    printf("Success!\n====================================\n"); \
} while (0);

// define some data structure for the tests
//
typedef struct Point {
    int x, y, z;
} Point;

int testQueueAppend(Queue* q) {
    Point* p1 = malloc(sizeof(Point));
    Point* p2 = malloc(sizeof(Point));
    Point* p3 = malloc(sizeof(Point));
    *p1 = (Point) {0, 1, 2};
    *p2 = (Point) {42, 43, 44};
    *p3 = (Point) {-1, -1, -1};

    queue_append(q, p1);
    queue_append(q, p2);
    queue_append(q, p3);

    CMP_POINTS((Point*)(q->head->data), p1);
    CMP_POINTS((Point*)(q->head->next->data), p2);
    CMP_POINTS((Point*)(q->head->next->next->data), p3);
    CMP_POINTS((Point*)(q->tail->data), p3);
}



int main(int argc, char **argv) {
    Queue* q = queue_new();
    testQueueAppend(q);
    printf("\n====================================\n"); \
    printf("All tests successful!\n");
    printf("====================================\n"); \
    
    return 0;
}
