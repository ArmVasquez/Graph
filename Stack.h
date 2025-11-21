#pragma once
#include "LinkedList.h"

#define MAX 10

template <typename T>
class Stack {
private:
    LinkedList<T> dataStack;
    int insertedElementCount;
    int stackSize;

public:
    Stack();
    ~Stack();

    // Stack operations
    bool push(T data);
    bool pop();
    T* getTop();
    bool isEmpty();
    bool isFull();
    void clearStack();
};

#include "Stack.tpp"