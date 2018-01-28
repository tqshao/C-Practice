#ifndef FIFO_QUEUE_CLASS_H_
#define FIFO_QUEUE_CLASS_H_
#include "LinkedNodeClass.h"
#include <iostream>

template<class T>
class FIFOQueueClass {
private:
    // Points to the first node in a queue, or NULL if queue is empty.
    LinkedNodeClass<T> *head;

    // Points to the last node in a queue, or NULL if queue is empty.
    LinkedNodeClass<T> *tail;

public:
    // Default Constructor. Will properly initialize a queue to
    // be an empty queue, to which values can be added.
    FIFOQueueClass();

    // Inserts the value provided (newItem) into the queue.
    void enqueue(const T &newItem);

    // Attempts to take the next item out of the queue. If the
    // queue is empty, the function returns false and the state
    // of the reference parameter (outItem) is undefined. If the
    // queue is not empty, the function returns true and outItem
    // becomes a copy of the next item in the queue, which is
    // removed from the data structure.
    bool dequeue(T &outItem);

    // Prints out the contents of the queue. All printing is done
    // on one line, using a single space to separate values, and a
    // single newline character is printed at the end.
    void print() const;

	// Destructor, which will free up all dynamic memory associated
	// with this queue when the list is destroyed (i.e when a statically
	// allocated queue goes out of scope or a dynamically allocated queue
	// is deleted).
	~FIFOQueueClass();
};

#include "FIFOQueueClass.inl"
#endif
