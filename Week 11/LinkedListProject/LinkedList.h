#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include "AddressBookType.h"
using namespace std;

class LinkedList : public AddressBookType
{
public:
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
    AddressBookType getNext();
    bool getHead();
    void sortAddressBook();
    AddressBookType searchAddressBook(string);
    void displayList();
    void saveToFile();
    void findSameBirthMonths();
    void findBetweenTwoLastNames();
    void printAllRelationshipType();
};

void LinkedList::appendNode(AddressBookType newValue)
{
    ListNode *newNode, *nodePtr;

    // create and init new node
    newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
        cout << "Added as first node." << endl;
    }
    else
    {
        nodePtr = head;

        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
        cout << "Added as subsequent node." << endl;
    }
}

void LinkedList::displayList()
{
    ListNode *nodePtr;
    int count = 0;

    if (!head)
    {
        cout << "Address book is empty!" << endl;
    }

    nodePtr = head;

    while (nodePtr)
    {
        cout << "Entry #" << ++count << endl;
        cout << nodePtr->value.getFirstName() << " " << nodePtr->value.getLastName() << endl;
        cout << nodePtr->value.getMonth() << "/" << nodePtr->value.getDay() << "/" << nodePtr->value.getYear() << endl;
        cout << nodePtr->value.getStreetAddress() << endl;
        cout << nodePtr->value.getCity() << ", " << nodePtr->value.getState() << " " << nodePtr->value.getZipCode() << endl;
        cout << nodePtr->value.getPhoneNumber() << endl;
        cout << nodePtr->value.getRelationship() << endl
             << endl;
        
        nodePtr = nodePtr->next;
    }
    cout << "Total entries: " << count << endl
         << endl;
}

void LinkedList::saveToFile()
{
    ofstream outFile("address_book.txt");
    ListNode *nodePtr;
    int count = 0;

    if (!head)
    {
        cout << "Address book is empty!" << endl;
    }

    nodePtr = head;

    while (nodePtr)
    {
        outFile << "Entry #" << ++count << endl;
        outFile << nodePtr->value.getFirstName() << " " << nodePtr->value.getLastName() << endl;
        outFile << nodePtr->value.getMonth() << "/" << nodePtr->value.getDay() << "/" << nodePtr->value.getYear() << endl;
        outFile << nodePtr->value.getStreetAddress() << endl;
        outFile << nodePtr->value.getCity() << ", " << nodePtr->value.getState() << " " << nodePtr->value.getZipCode() << endl;
        outFile << nodePtr->value.getPhoneNumber() << endl;
        outFile << nodePtr->value.getRelationship() << endl
             << endl;
        
        nodePtr = nodePtr->next;
    }
    cout << "Total entries: " << count << endl
         << endl;
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

AddressBookType LinkedList::getNext()
{
    if (!head)
        return AddressBookType();
        
    AddressBookType temp = head->value;
    head = head->next;
    return temp;
}

void LinkedList::sortAddressBook()
{
    if (!head || !head->next) return;

    bool swapped;
    ListNode* ptr1;
    ListNode* lptr = NULL;

    do
    {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->value.getLastName() > ptr1->next->value.getLastName())
            {
                // Swap the values instead of the nodes
                AddressBookType temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

    cout << "Address book sorted successfully." << endl
         << endl;
}


AddressBookType LinkedList::searchAddressBook(string searchValue)
{
    ListNode* nodePtr = head;
    
    while (nodePtr != NULL)
    {
        if (nodePtr->value.getLastName() == searchValue)
        {
            return nodePtr->value;
        }
        nodePtr = nodePtr->next;
    }
    
    cout << "Person not found." << endl;
    return AddressBookType(); // Return empty AddressBookType if not found
}

bool LinkedList::getHead()
{
    if (head == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
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

void LinkedList::findSameBirthMonths()
{
    bool found = false;
    int month;
    
    cout << "Enter the birth month (1-12): ";
    cin >> month;
    
    if (month < 1 || month > 12) {
        cout << "Invalid month. Please enter a number between 1 and 12." << endl;
        return;
    }
    
    ListNode *current = head;
    
    cout << "People born in month " << month << ":" << endl;
    while (current != nullptr) {
        if (current->value.getMonth() == month) {
            cout << current->value.getFirstName() << " " 
                 << current->value.getLastName() << endl;
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "No entries found with birth month " << month << "." << endl;
    }
    cout << endl;
}

void LinkedList::findBetweenTwoLastNames()
{
    string lastName1, lastName2;
    bool found = false;
    
    cout << "Enter the first last name: ";
    cin >> lastName1;
    cout << "Enter the second last name: ";
    cin >> lastName2;
    
    // Ensure lastName1 is lexicographically smaller than lastName2
    if (lastName1 > lastName2) {
        swap(lastName1, lastName2);
    }
    
    ListNode *current = head;
    
    cout << "Addresses between " << lastName1 << " and " << lastName2 << ":" << endl;
    
    while (current != nullptr) {
        if (current->value.getLastName() > lastName1 && 
            current->value.getLastName() < lastName2) {
            current->value.displayAddressBook();
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "No entries found between " << lastName1 << " and " 
             << lastName2 << "." << endl;
    }
    cout << endl;
}

void LinkedList::printAllRelationshipType()
{
    string relationshipType;
    bool found = false;
    
    cout << "Enter the relationship type (Family/Friend/Business): ";
    cin >> relationshipType;
    
    ListNode *current = head;
    
    while (current != nullptr) {
        string currentRelation = current->value.getRelationship();
        
        if (currentRelation == relationshipType) {
            current->value.displayAddressBook();
            found = true;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "No entries found with relationship type: " << relationshipType << endl;
    }
    cout << endl;
}

#endif // LINKEDLIST_H