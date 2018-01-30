#include "SortedListClass.h"


SortedListClass::SortedListClass() {
    head = 0;
    tail = 0;
}


SortedListClass::SortedListClass(const SortedListClass &rhs) {
    if (rhs.head == 0) {
        return;
    }

    head = new LinkedNodeClass(0, rhs.head->getValue(), 0);
    LinkedNodeClass *prev = head;
    LinkedNodeClass *next = 0;
    LinkedNodeClass *pointer = rhs.head->getNext();

    while (pointer != 0) {
        next = new LinkedNodeClass(prev, pointer->getValue(), 0);
        next->setBeforeAndAfterPointers();
        prev = next;
        pointer = pointer->getNext();
    }
    
    tail = prev;
}


void SortedListClass::clear() {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        LinkedNodeClass *next = pointer->getNext();
        delete pointer;
        pointer = next;
    }
    head = 0;
    tail = 0;
}


void SortedListClass::insertValue(const int &valToInsert) {
    if (head == 0) {
        head = new LinkedNodeClass(0, valToInsert, 0);
        tail = head;
        return;
    }

    if (valToInsert < head->getValue()) {
        LinkedNodeClass *newNode = new LinkedNodeClass(0, valToInsert, head);
        newNode->setBeforeAndAfterPointers();
        head = newNode;
        return;
    }

    LinkedNodeClass *pointer = head;
    while (pointer != 0 && pointer->getValue() <= valToInsert) {
        pointer = pointer->getNext();
    }
    if (pointer == 0) {
        LinkedNodeClass *newNode = new LinkedNodeClass(tail, valToInsert, 0);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    } else {
        LinkedNodeClass *newNode = new LinkedNodeClass(pointer->getPrev(),
                valToInsert, pointer);
        newNode->setBeforeAndAfterPointers();
    }
}


void SortedListClass::printForward() const {
    std::cout << "Forward List Contents Follow:" << std::endl;
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        std::cout << pointer->getValue() << std::endl;
        pointer = pointer->getNext();
    }
    std::cout << "End Of List Contents" << std::endl;
}


void SortedListClass::printBackward() const {
    std::cout << "Backward List Contents Follow:" << std::endl;
    LinkedNodeClass *pointer = tail;
    while (pointer != 0) {
        std::cout << pointer->getValue() << std::endl;
        pointer = pointer->getPrev();
    }
    std::cout << "End Of List Contents" << std::endl;
}


bool SortedListClass::removeFront(int &theVal) {
    if (head == 0) {
        return false;
    }
    theVal = head->getValue();
    head = head->getNext();

    if (head != 0) {
        head->setPreviousPointerToNull();
    } else {
        tail = 0;
    }

    return true;
}


bool SortedListClass::removeLast(int &theVal) {
    if (tail == 0) {
        return false;
    }
    theVal = tail->getValue();
    tail = tail->getPrev();

    if (tail != 0) {
        tail->setNextPointerToNull();
    } else {
        head = 0;
    }

    return true;
}


int SortedListClass::getNumElems() const {
    LinkedNodeClass *pointer = head;
    int count = 0;
    while (pointer != 0) {
        pointer = pointer->getNext();
        count++;
    }
    return count;
}


bool SortedListClass::getElemAtIndex(const int index, int &outVal) {
    if (index < 0) {
        return false;
    }

    LinkedNodeClass *pointer = head;
    int count = 0;
    while (pointer != 0 && count != index) {
        pointer = pointer->getNext();
        count++;
    }

    if (count == index && pointer != 0) {
        outVal = pointer->getValue();
        return true;
    }

    return false;
}
