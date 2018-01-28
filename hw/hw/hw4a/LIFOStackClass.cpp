#include "LIFOStackClass.h"


LIFOStackClass::LIFOStackClass() {
    head = 0;
    tail = 0;
}


void LIFOStackClass::push(const int &newItem) {
    if (tail == 0) {
        tail = new LinkedNodeClass(0, newItem, 0);
        head = tail;
        return;
    }
    
    LinkedNodeClass *newTail = new LinkedNodeClass(tail, newItem, 0);
    newTail->setBeforeAndAfterPointers();
    tail = newTail;
}


bool LIFOStackClass::pop(int &outItem) {
    if (tail == 0) {
        return false;
    }

    if (tail == head) {
        outItem = tail->getValue();
        delete tail;
        head = 0;
        tail = 0;
        return true;
    }

    LinkedNodeClass *newTail = tail->getPrev();
    outItem = tail->getValue();
    newTail->setNextPointerToNull();
    tail = newTail;
    return true;
}


void LIFOStackClass::print() const {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        std::cout << pointer->getValue() << " ";
        pointer = pointer->getNext();
    }
    std::cout << std::endl;
}


void LIFOStackClass::clear() {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        LinkedNodeClass *next = pointer->getNext();
        delete pointer;
        pointer = next;
    }
    head = 0;
    tail = 0;
}
