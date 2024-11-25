#ifndef INTQUEUE_H
#define INTQUEUE_H
#include <iostream>
#include <memory>
using namespace std;

class IntQueue
{
private:
    unique_ptr<int []> queueArray;
    // int queueArray[100];
    int queueSize;
    int front;
    int rear;
    int numItems;

public:
    IntQueue(int);
    void enqueue(int);
    void dequeue(int&);
    bool isEmpty();
    bool isFull();
    void clear();
};

IntQueue::IntQueue(int size)
{
    queueArray = make_unique<int[]>(size);
    // int queueArray[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

void IntQueue::enqueue(int num)
{
    if (isFull())
    {
        cout << "Queue is full. Cannot enqueue " << num << endl;
        exit(1);
    }
    else
    {
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Insert new item
        queueArray[rear] = num;
        // Update item count
        numItems++;
    }
}

void IntQueue::dequeue(int& num)
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue" << endl;
        exit(1);
    }
    else
    {
        // move front
        front = (front + 1) % queueSize;
        // Get the front item
        num = queueArray[front];
        // Update item count
        numItems--;
    }
}

bool IntQueue::isEmpty()
{
    return numItems == 0;
}

bool IntQueue::isFull()
{
    return numItems == queueSize;
}

void IntQueue::clear()
{
    front = -1;
    rear = -1;
    numItems = 0;
}

#endif // INTQUEUE_H