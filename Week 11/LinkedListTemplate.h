#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template<typename T>
class LinkedList
{
private:
    struct ListNode
    {
        T value;
        struct ListNode *next;
    };

    ListNode *head;

public:
    LinkedList() {head = nullptr;}
    ~LinkedList();
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList();
};

template<typename T>
void LinkedList<T>::appendNode(T newValue)
{
    ListNode *newNode, *nodePtr;

    newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = NULL;
    
    if (!head) {
        head = newNode;
    }
    else
    {
        nodePtr = head;

        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

template<typename T>
void LinkedList<T>::displayList()
{
    ListNode *nodePtr;

    nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

template<typename T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode *newNode, *nodePtr, *previousNode = NULL;

    newNode = new ListNode;
    newNode->value = newValue;

    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;
        previousNode = NULL;

        while (nodePtr != NULL && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

template<typename T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode *nodePtr, *previousNode;

    if (!head)
        return;

    if (head->value == searchValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr!= NULL && nodePtr->value!= searchValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr, *nextNode;
    
    nodePtr = head;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

#endif // LINKEDLIST_H