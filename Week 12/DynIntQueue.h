#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H
#include <iostream>
using namespace std;

class DynIntQueue
{
private:
    struct QueueNode
    {
        int value;
        QueueNode *next;
        QueueNode(int value1, QueueNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    // These track the front and rear of the queue
    QueueNode *front;
    QueueNode *rear;

public:
    DynIntQueue();
    ~DynIntQueue();
    void enqueue(int);
    void dequeue(int&);
    bool isEmpty() const;
    void clear();
};

DynIntQueue::DynIntQueue()
{
    front = nullptr;
    rear = nullptr;
}

DynIntQueue::~DynIntQueue()
{
    QueueNode *garbage = front;
    while (garbage != nullptr)
    {
        front = front->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = front;
    }
}

void DynIntQueue::enqueue(int num)
{
    if (isEmpty())
    {
        front = new QueueNode(num);
        rear = front;
    }
    else 
    {
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
}

void DynIntQueue::dequeue(int& num)
{
    QueueNode *temp = nullptr;
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue " << num << endl;
        exit(1);
    }
    else 
    {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool DynIntQueue::isEmpty() const
{
    if (front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DynIntQueue::clear()
{
    int value;
    while (!isEmpty())
    {
        dequeue(value);
    }
}

#endif // DYNINTQUEUE_H