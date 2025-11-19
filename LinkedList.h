#pragma once

template <typename T>
class LinkedList {
private: 
	// Node class
	class Node {
	public:
		T data;
		Node* next;

		Node(T data);
	};

	Node *head;

public:
	// Iterator class
	class Iterator {
	public:
		Iterator(Node* ptr);
		Iterator& operator++();
		Iterator operator++(int);
		bool operator!=(const Iterator& other) const;
		bool operator==(const Iterator& other) const;
		T& operator*() const;
		T* operator->() const;

	private:
		Node* current;
	};

	Iterator begin() const;
	Iterator end() const;

	// Constructors and destructors
	LinkedList();
	~LinkedList();

	// Disabling copy constructor and assignment operator
	LinkedList(const LinkedList& other) = delete;
	LinkedList& operator=(const LinkedList& other) = delete;


	// Methods
	bool insertAtStart(T data);
	bool insertAtEnd(T data);
	bool insertAtPosition(T data, unsigned int position);
	
	bool deleteElement(unsigned int position);
	bool deleteFromStart();
	bool deleteFromEnd();
	bool deleteList();

	Node* find(T data);
	void printList();


};

#include "LinkedList.tpp"
