#pragma once
#include "LinkedList.h"

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    // Methods
    bool enqueue(T data);
    bool dequeue();
    T* getFront();
    bool isEmpty();
    void clearQueue();

private:
    LinkedList<T> queueList;
    int insertedElementCount;
};

#include "Queue.tpp"