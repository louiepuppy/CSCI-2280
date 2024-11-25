#ifndef DYNQUEUE_H
#define DYNQUEUE_H
#include <iostream>
using namespace std;

template<typename T>
class DynQueue
{
private:
    struct QueueNode
    {
        T value;
        QueueNode *next;
        QueueNode(T value1, QueueNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    // These track the front and rear of the queue
    QueueNode *front;
    QueueNode *rear;

public:
    DynQueue();
    ~DynQueue();
    void enqueue(T);
    void dequeue(T&);
    bool isEmpty() const;
    void clear();
};

template<typename T>
DynQueue<T>::DynQueue()
{
    front = nullptr;
    rear = nullptr;
}

template<typename T>
DynQueue<T>::~DynQueue()
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

template<typename T>
void DynQueue<T>::enqueue(T value)
{
    if (isEmpty())
    {
        front = new QueueNode(value);
        rear = front;
    }
    else 
    {
        rear->next = new QueueNode(value);
        rear = rear->next;
    }
}

template<typename T>
void DynQueue<T>::dequeue(T& value)
{
    QueueNode *temp = nullptr;
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue " << value << endl;
        exit(1);
    }
    else 
    {
        value = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<typename T>
bool DynQueue<T>::isEmpty() const
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

template<typename T>
void DynQueue<T>::clear()
{
    T value;
    while (!isEmpty())
    {
        dequeue(value);
    }
}

#endif // DYNQUEUE_H