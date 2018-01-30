#include "FIFOQueueClass.h"


FIFOQueueClass::FIFOQueueClass() {
    head = 0;
    tail = 0;
}


void FIFOQueueClass::enqueue(const int &newItem) {
    if (tail == 0) {
        tail = new LinkedNodeClass(0, newItem, 0);
        head = tail;
        return;
    }
    
    LinkedNodeClass *newTail = new LinkedNodeClass(tail, newItem, 0);
    newTail->setBeforeAndAfterPointers();
    tail = newTail;
}


bool FIFOQueueClass::dequeue(int &outItem) {
    if (head == 0) {
        return false;
    }

    if (head == tail) {
        outItem = head->getValue();
        delete head;
        head = 0;
        tail = 0;
        return true;
    }

    LinkedNodeClass *newHead = head->getNext();
    outItem = head->getValue();
    newHead->setPreviousPointerToNull();
    head = newHead;
    return true;
}


void FIFOQueueClass::print() const {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        std::cout << pointer->getValue() << " ";
        pointer = pointer->getNext();
    }
    std::cout << std::endl;
}


void FIFOQueueClass::clear() {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        LinkedNodeClass *next = pointer->getNext();
        delete pointer;
        pointer = next;
    }
    head = 0;
    tail = 0;
}
