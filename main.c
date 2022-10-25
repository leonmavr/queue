#include "queue.h"
#include <stdio.h>


typedef struct Point {
    int x, y, z;
} Point;

int main(int argc, char **argv) {
    Point p = (Point) {0, 1, 2};
    Point p2 = (Point) {42, 43, 44};
    Point p3 = (Point) {-1, -1, -1};
    Point* popped;
    Queue* q = queue_new();
    queue_append(q, &p2);
    queue_append(q, &p);
    popped = (Point*)(queue_pop(q));
    printf("%d\n", popped->x);
    queue_append(q, &p3);
    queue_append(q, &p3);
    queue_size(q);
    queue_delete(q);
    return 0;
}
