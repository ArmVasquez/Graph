template <typename T>
Stack<T>::Stack() {
    insertedElementCount = -1;
    stackSize = MAX;
}

template <typename T>
Stack<T>::~Stack() {
    // Reset the stack
    clearStack();
}

template <typename T>
bool Stack<T>::push(T data) {
    // Check if the stack is full
    if (isFull()) {
        return false;
    }

    // Add the value to the stack
    insertedElementCount++;
    if (!dataStack.insertAtStart(data)) {
        return false;
    }

    return true;
}

template <typename T>
bool Stack<T>::isFull() {
    // Check if the stack has reached its maximum size
    if (insertedElementCount == MAX - 1) {
        return true;
    }

    return false;
}

template <typename T>
bool Stack<T>::pop() {
    // Check if the stack is empty
    if (isEmpty()) {
        return false;
    }

    // Remove the top element from the stack
    if (!dataStack.deleteFromStart()) {
        return false;
    }

    insertedElementCount--;
    return true;
}

template <typename T>
T* Stack<T>::getTop() {
    // Return the top element of the stack
    if (isEmpty()) {
        return nullptr;
    }

    auto it = dataStack.begin();
    
    // Iterator dereference gives access to node data and return its address
    return &(*it);
}

template <typename T>
bool Stack<T>::isEmpty() {
    // Check if the stack is empty
    if (insertedElementCount == -1) {
        return true;
    }

    return false;
}

template <typename T>
void Stack<T>::clearStack() {
    if (isEmpty()) {
        return;
    }
    // Clear the stack by resetting all elements
    insertedElementCount = -1;
    dataStack.deleteList();
}
