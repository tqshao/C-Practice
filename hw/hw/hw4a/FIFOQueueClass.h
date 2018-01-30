#ifndef FIFO_QUEUE_CLASS_H_
#define FIFO_QUEUE_CLASS_H_
#include "LinkedNodeClass.h"
#include <iostream>

class FIFOQueueClass {
private:
    // Points to the first node in a queue, or NULL if queue is empty.
    LinkedNodeClass *head;

    // Points to the last node in a queue, or NULL if queue is empty.
    LinkedNodeClass *tail;

public:
    // Default Constructor. Will properly initialize a queue to
    // be an empty queue, to which values can be added.
    FIFOQueueClass();

    // Inserts the value provided (newItem) into the queue.
    void enqueue(const int &newItem);

    // Attempts to take the next item out of the queue. If the
    // queue is empty, the function returns false and the state
    // of the reference parameter (outItem) is undefined. If the
    // queue is not empty, the function returns true and outItem
    // becomes a copy of the next item in the queue, which is
    // removed from the data structure.
    bool dequeue(int &outItem);

    // Prints out the contents of the queue. All printing is done
    // on one line, using a single space to separate values, and a
    // single newline character is printed at the end.
    void print() const;

    // Clears the queue to an empty state without resulting in any
    // memory leaks.
    void clear();
};

#endif
