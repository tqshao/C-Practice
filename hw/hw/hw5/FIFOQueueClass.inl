template<class T>
FIFOQueueClass<T>::FIFOQueueClass() {
    head = 0;
    tail = 0;
}


template<class T>
void FIFOQueueClass<T>::enqueue(const T &newItem) {
    if (tail == 0) {
        tail = new LinkedNodeClass<T>(0, newItem, 0);
        head = tail;
        return;
    }
    
    LinkedNodeClass<T> *newTail = new LinkedNodeClass<T>(tail, newItem, 0);
    newTail->setBeforeAndAfterPointers();
    tail = newTail;
}


template<class T>
bool FIFOQueueClass<T>::dequeue(T &outItem) {
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

    LinkedNodeClass<T> *newHead = head->getNext();
    outItem = head->getValue();
    newHead->setPreviousPointerToNull();
    head = newHead;
    return true;
}


template<class T>
void FIFOQueueClass<T>::print() const {
    LinkedNodeClass<T> *pointer = head;
    while (pointer != 0) {
        std::cout << pointer->getValue() << " ";
        pointer = pointer->getNext();
    }
    std::cout << std::endl;
}


template<class T>
FIFOQueueClass<T>::~FIFOQueueClass() {
	LinkedNodeClass<T> *pointer = head;
	while (pointer != 0) {
		LinkedNodeClass<T> *next = pointer->getNext();
		delete pointer;
		pointer = next;
	}
	head = 0;
	tail = 0;
}