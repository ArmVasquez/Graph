#include <iostream>
#include <new>

template <class T>
LinkedList<T>::Iterator::Iterator(Node* ptr) : current(ptr) {}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    if (current) current = current->next;
    return *this;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <class T>
bool LinkedList<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template <class T>
T& LinkedList<T>::Iterator::operator*() const {
    return current->data;
}

template <class T>
T* LinkedList<T>::Iterator::operator->() const {
    return &(current->data);
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
    return Iterator(head);
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    return Iterator(nullptr);
}

template <class T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <class T>
LinkedList<T>::~LinkedList() {
   deleteList();
}

template <class T>
LinkedList<T>::Node::Node(T data) : data(data), next(nullptr) {}

template <class T>
bool LinkedList<T>::insertAtStart(T data) {
    // Creating dynamic memory for the element
    Node *newNode = nullptr;
    newNode = new(std::nothrow) Node(data);

    // Checking if dynamic memory was allocated
    if (!newNode) {
        return false;
    }

    // Inserting new node
    newNode->next = head;

    head = newNode;

    return true;
}

template <class T>
bool LinkedList<T>::insertAtEnd(T data) {
    // Creating dynamic memory for the element
    Node *newNode = nullptr;
    newNode = new(std::nothrow) Node(data);

    // Checking if dynamic memory was allocated
    if (!newNode) {
        return false;
    }

    // Checking if list is empty
    if (head == nullptr) {
        head = newNode;
        return true;
    }

    // Inserting new node
    Node *current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;

    return true;
}

template <class T>
bool LinkedList<T>::insertAtPosition(T data, unsigned int position) {
    // Inserting at start if position is 0
    if (position == 0) {
        return insertAtStart(data);
    }

    // Moving until finding position
    Node *current = head;
    unsigned int listPosition = 0;

    while (listPosition != position - 1) {
        if (current == nullptr) {
            return false;
        }
        current = current->next;
        listPosition++;
    }

    // Creating dynamic memory for the element
    Node *newNode = nullptr;
    newNode = new(std::nothrow) Node(data);

    // Checking if dynamic memory was allocated
    if (!newNode) {
        return false;
    }

    // Inserting new node
    newNode->next = current->next;
    current->next = newNode;

    return true;
}

template <class T>
bool LinkedList<T>::deleteElement(unsigned int position) {
	// Helper for deleting first position
	if (position == 0) {
		return deleteFromStart();
	}

    // Evaluating if list is empty
    if (head == nullptr) {
        return false;
    }

	//Moving until finding position
	Node *current = head;
	unsigned int listPosition = 0;

	while (listPosition != position - 1) {
		if (current->next == nullptr) {
			return false;
		}
		current = current->next;
		listPosition++;
	}

	// Correcting values in list
	Node *nodeToDelete = current->next;
	current->next = nodeToDelete->next;

	delete nodeToDelete;
    nodeToDelete = nullptr;
	return true;
}

template <class T>
bool LinkedList<T>::deleteFromStart() {
    // Evaluating if list is empty
    if (head == nullptr) {
        return false;
    }

    // Deleting first element
    Node *nodeToDelete = head;
    head = head->next;

    delete nodeToDelete;
    nodeToDelete = nullptr;
    return true;
}

template <class T>
bool LinkedList<T>::deleteFromEnd() {
    // Evaluating if list is empty
    if (head == nullptr) {
        return false;
    }

    // One element in list
    if (head->next == nullptr) {
        return deleteFromStart();
    }

    // Deleting last element
    Node *current = head;

    while (current->next->next != nullptr) {
        current = current->next;
    }

    Node *nodeToDelete = current->next;
    current->next = nullptr;

    delete nodeToDelete;
    nodeToDelete = nullptr;
    return true;
}

template <class T>
bool LinkedList<T>::deleteList() {
    // Evaluating if list is empty
    if (head == nullptr) {
        return false;
    }

    // Deleting all elements
    Node *current = head;
    Node *nodeToDelete = nullptr;

    while (current != nullptr) {
        nodeToDelete = current;
        current = current->next;

        delete nodeToDelete;
        nodeToDelete = nullptr;
    }

    head = nullptr;
    return true;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(T data) {
    Node *current = head;

    // Evaluating if list is empty
    if (current == nullptr) {
        return nullptr;
    }

    // Evaluating all elements in list
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }

        current = current->next;
    }

    // If there is no match, we return nullptr
    return nullptr;
}

template <class T>
void LinkedList<T>::printList() {
    Node *current = head;

    // Evaluating if list is empty
    if (current == nullptr) {
        return;
    }

    // Printing all elements in list
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    
    return;
}