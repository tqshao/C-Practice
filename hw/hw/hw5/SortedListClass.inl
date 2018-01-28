template<class T>
SortedListClass<T>::SortedListClass() {
    head = 0;
    tail = 0;
}


template<class T>
SortedListClass<T>::SortedListClass(const SortedListClass<T> &rhs) {
    if (rhs.head == 0) {
        return;
    }

    head = new LinkedNodeClass<T>(0, rhs.head->getValue(), 0);
    LinkedNodeClass<T> *prev = head;
    LinkedNodeClass<T> *next = 0;
    LinkedNodeClass<T> *pointer = rhs.head->getNext();

    while (pointer != 0) {
        next = new LinkedNodeClass<T>(prev, pointer->getValue(), 0);
        next->setBeforeAndAfterPointers();
        prev = next;
        pointer = pointer->getNext();
    }
    
    tail = prev;
}


template<class T>
void SortedListClass<T>::operator=(const SortedListClass<T>& rhs) {
	SortedListClass<T>::SortedListClass(rhs);
}


template<class T>
void SortedListClass<T>::clear() {
    LinkedNodeClass<T> *pointer = head;
    while (pointer != 0) {
        LinkedNodeClass<T> *next = pointer->getNext();
        delete pointer;
        pointer = next;
    }
    head = 0;
    tail = 0;
}


template<class T>
void SortedListClass<T>::insertValue(const T &valToInsert) {
    if (head == 0) {
        head = new LinkedNodeClass<T>(0, valToInsert, 0);
        tail = head;
        return;
    }

    if (valToInsert < head->getValue()) {
        LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(0, valToInsert, head);
        newNode->setBeforeAndAfterPointers();
        head = newNode;
        return;
    }

    LinkedNodeClass<T> *pointer = head;
    while (pointer != 0 && pointer->getValue() <= valToInsert) {
        pointer = pointer->getNext();
    }
    if (pointer == 0) {
        LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(tail, valToInsert, 0);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    } else {
        LinkedNodeClass<T> *newNode = new LinkedNodeClass<T>(pointer->getPrev(),
                valToInsert, pointer);
        newNode->setBeforeAndAfterPointers();
    }
}


template<class T>
void SortedListClass<T>::printForward() const {
    std::cout << "Forward List Contents Follow:" << std::endl;
    LinkedNodeClass<T> *pointer = head;
    while (pointer != 0) {
        std::cout << pointer->getValue() << std::endl;
        pointer = pointer->getNext();
    }
    std::cout << "End Of List Contents" << std::endl;
}


template<class T>
void SortedListClass<T>::printBackward() const {
    std::cout << "Backward List Contents Follow:" << std::endl;
    LinkedNodeClass<T> *pointer = tail;
    while (pointer != 0) {
        std::cout << pointer->getValue() << std::endl;
        pointer = pointer->getPrev();
    }
    std::cout << "End Of List Contents" << std::endl;
}


template<class T>
bool SortedListClass<T>::removeFront(T &theVal) {
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


template<class T>
bool SortedListClass<T>::removeLast(T &theVal) {
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


template<class T>
int SortedListClass<T>::getNumElems() const {
    LinkedNodeClass<T> *pointer = head;
    int count = 0;
    while (pointer != 0) {
        pointer = pointer->getNext();
        count++;
    }
    return count;
}


template<class T>
bool SortedListClass<T>::getElemAtIndex(const int index, T &outVal) {
    if (index < 0) {
        return false;
    }

    LinkedNodeClass<T> *pointer = head;
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


template<class T>
SortedListClass<T>::~SortedListClass() {
	LinkedNodeClass<T> *pointer = head;
	while (pointer != 0) {
		LinkedNodeClass<T> *next = pointer->getNext();
		delete pointer;
		pointer = next;
	}
	head = 0;
	tail = 0;
}
