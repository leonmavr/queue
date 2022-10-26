# queue
Generic header-only implementation of a queue.

### About
It implements the queue (a FIFO data strcuture - the first element to be added to the queue will be the first element to be removed from the queue) more or less as defined [here](https://isaaccomputerscience.org/concepts/dsa_datastruct_queue?examBoard=all&stage=all). However, there a couple of small deviations from the definition:
* function `enqueue(data)` is named `append(data)` and `dequeue()` is named `pop()`.
* The is no maximum capacity. User is free to add any amount of data.

### Usage
There is no `main.c`. The makefile runs some unit tests (found in `tests/tests.c`) that assert that `append` and `pop` work correctly. You can run them with `make` and clean them with `make clean`.

### Example
The example below demonstrates how it's used with a user-defined data structure.

```
#include "queue.h"
#include <stdio.h>


typedef struct Point {
    int x, y, z;
} Point;

int main(int argc, char **argv) {
    Point* p1 = malloc(sizeof(Point));
    Point* p2 = malloc(sizeof(Point));
    Point* p3 = malloc(sizeof(Point));
    Point* popped;
    *p1 = (Point) {0, 1, 2};
    *p2 = (Point) {42, 43, 44};
    *p3 = (Point) {-1, -1, -1};

    Queue* q = queue_new();
    // +3
    queue_append(q, p1);
    queue_append(q, p2);
    queue_append(q, p3);
    // -3
    popped = (Point*) queue_pop(q);
    popped = (Point*) queue_pop(q);
    popped = (Point*) queue_pop(q);
    /*
    printf("popped: %d, %d, %d\n",
        popped->x,
        popped->y,
        popped->z);
    */
    // +1
    queue_append(q, p3);

    // 1
    printf("size = %d\n", queue_size(q));

    free(p1);
    free(p2);
    free(p3);
    queue_delete(q);
    return 0;
}
```
