#include "LinkedNodeClass.h"


LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev,
                                 const int &inVal,
                                 LinkedNodeClass *inNext) {
    prevNode = inPrev;
    nodeVal = inVal;
    nextNode = inNext;
}


int LinkedNodeClass::getValue() const {
    return nodeVal;
}


LinkedNodeClass* LinkedNodeClass::getNext() const {
    return nextNode;
}


LinkedNodeClass* LinkedNodeClass::getPrev() const {
    return prevNode;
}


void LinkedNodeClass::setNextPointerToNull() {
    if (nextNode != 0) {
        delete nextNode;
        nextNode = 0;
    }
}


void LinkedNodeClass::setPreviousPointerToNull() {
    if (prevNode != 0) {
        delete prevNode;
        prevNode = 0;
    }
}


void LinkedNodeClass::setBeforeAndAfterPointers() {
    if (prevNode != 0) {
        prevNode->nextNode = this;
    }
    if (nextNode != 0) {
        nextNode->prevNode = this;
    }
}
