#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "AddressBookType.h"
using namespace std;

class LinkedList : public AddressBookType
{
private:
    struct ListNode
    {
        AddressBookType value;
        struct ListNode *next;
    };

    ListNode *head;

public:
    LinkedList() {head = nullptr;}
    ~LinkedList();
    void appendNode(AddressBookType);
    void insertNode(AddressBookType);
    void deleteNode(AddressBookType);
    void sortAddressBook();
    AddressBookType searchAddressBook(string);
    void displayList();
};

void LinkedList::appendNode(AddressBookType newValue)
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

void LinkedList::displayList()
{
    ListNode *nodePtr;

    nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->value.getFirstName() << " " << nodePtr->value.getLastName() << endl;
        cout << nodePtr->value.getMonth() << "/" << nodePtr->value.getDay() << "/" << nodePtr->value.getYear() << endl;
        cout << nodePtr->value.getStreetAddress() << endl;
        cout << nodePtr->value.getCity() << ", " << nodePtr->value.getState() << " " << nodePtr->value.getZipCode() << endl;
        cout << nodePtr->value.getPhoneNumber() << endl;
        cout << nodePtr->value.getRelationship() << endl
             << endl;
        nodePtr = nodePtr->next;
    }
}

void LinkedList::insertNode(AddressBookType newValue)
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

        while (nodePtr != NULL && nodePtr->value.getLastName() < newValue.getLastName())
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

void LinkedList::deleteNode(AddressBookType searchValue)
{
    ListNode *nodePtr, *previousNode;

    if (!head)
        return;

    if (head->value.getLastName() == searchValue.getLastName())
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr!= NULL && nodePtr->value.getLastName() != searchValue.getLastName())
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

void LinkedList::sortAddressBook()
{
    ListNode *nodePtr, *nextNode, *temp;
    
    if (head == NULL)
    {
        return;
    }
    
    for (nodePtr = head; nodePtr!= NULL; nodePtr = nodePtr->next)
    {
        for (nextNode = nodePtr->next; nextNode!= NULL; nextNode = nextNode->next)
        {
            if (nodePtr->value.getLastName() > nextNode->value.getLastName())
            {
                temp = nodePtr->next;
                nodePtr->next = nextNode->next;
                nextNode->next = nodePtr;
                nodePtr = temp;
            }
        }
        head = nodePtr; // Update head pointer to the smallest value node after sorting
    }
    
    cout << "Address book sorted successfully." << endl;
}

AddressBookType LinkedList::searchAddressBook(string searchValue)
{
    ListNode *nodePtr;
    
    nodePtr = head;
    while (nodePtr!= NULL && nodePtr->value.getLastName()!= searchValue)
    {
        nodePtr = nodePtr->next;
        if (nodePtr == NULL)
        {
            cout << "Person not found." << endl;
            return AddressBookType(); // Return an empty AddressBookType if not found
        }
        return nodePtr->value; // Return the found AddressBookType
    }
    return AddressBookType(); // Return an empty AddressBookType if not found
}



LinkedList::~LinkedList()
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