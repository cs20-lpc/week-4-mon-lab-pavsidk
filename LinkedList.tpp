template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    Node* t = new Node;
    t->value = elem;
    t->next = nullptr;
    
    if(head == nullptr) {
        head = t;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = t;
    }
    this->length+=1;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* curr = head;
    Node* t;
    while(curr != nullptr) {
        t = curr->next;
        delete curr;
        curr = t;
    }
    head = nullptr;
    this->length=0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    Node* curr = head;
    if (position < 0) {
        throw string("getElement: error, position must be non-negative");
    }
    for (int i=0; i<=position; i++) {
        if (curr == nullptr) {
            throw string("getElement: error, position is out of bounds");
        }
        if (i == position) {
            return curr->value;
        }
        curr = curr->next;
    }
    throw string("getElement: error, position is out of bounds");
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    Node* curr = head;
    if (position < 0) {
        throw string("replace: error, position must be non-negative");
    }
    for (int i=0; i<position; i++) {
            if (curr == nullptr) {
                throw string("replace: error, position is out of bounds");
            }
            curr = curr->next;
    }
    if (curr == nullptr) {
        throw string("replace: error, position is out of bounds");
    }
    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
