template<class T>
LIFOStackClass<T>::LIFOStackClass() {
    head = 0;
    tail = 0;
}


template<class T>
void LIFOStackClass<T>::push(const T &newItem) {
    if (tail == 0) {
        tail = new LinkedNodeClass(0, newItem, 0);
        head = tail;
        return;
    }
    
    LinkedNodeClass *newTail = new LinkedNodeClass(tail, newItem, 0);
    newTail->setBeforeAndAfterPointers();
    tail = newTail;
}


template<class T>
bool LIFOStackClass<T>::pop(T &outItem) {
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


template<class T>
void LIFOStackClass<T>::print() const {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        std::cout << pointer->getValue() << " ";
        pointer = pointer->getNext();
    }
    std::cout << std::endl;
}


template<class T>
void LIFOStackClass<T>::clear() {
    LinkedNodeClass *pointer = head;
    while (pointer != 0) {
        LinkedNodeClass *next = pointer->getNext();
        delete pointer;
        pointer = next;
    }
    head = 0;
    tail = 0;
}
