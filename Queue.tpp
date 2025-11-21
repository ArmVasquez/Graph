template <typename T>
Queue<T>::Queue() {
    // Constructor
    insertedElementCount = -1;
}

template <typename T>
Queue<T>::~Queue() {
    // Destructor
    clearQueue();
}

template <typename T>
bool Queue<T>::enqueue(T data) {
    if (!queueList.insertAtEnd(data)) {
        return false;
    }

    insertedElementCount++;
    return true;
}

template <typename T>
bool Queue<T>::dequeue() {
    // Checking if queue is empty
    if (isEmpty()) {
        return false;
    }

    if (!queueList.deleteFromStart()) {
        return false;
    }

    insertedElementCount--;
    return true;
}

template <typename T>
T* Queue<T>::getFront() {
    // Returning nullptr if queue is empty
    if (isEmpty()) {
        return nullptr;
    }

    auto it = queueList.begin();

    // Iterator dereference gives access to node data and return its address
    return &(*it);
}

template <typename T>
bool Queue<T>::isEmpty() {
    // Check if the queue is empty
    if (insertedElementCount == -1) {
        return true;
    }

    return false;
}

template <typename T>
void Queue<T>::clearQueue() {
    if (isEmpty()) {
        return;
    }

    queueList.deleteList();
    insertedElementCount = -1;
}