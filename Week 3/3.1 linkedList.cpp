#include <iostream>
#include <string>
using namespace std;

// Step 1: Define class ContactNode

// Step 2: Define main() to read the name and phone number for three contacts and output each contact.
// Create three ContactNodes and use the nodes to build a linked list.

// Step 3: Output the linked list. Use a loop to call each node's PrintContactNode().


class ContactNode
{
public:
    /* Declare member functions here */
    string GetName();
    string GetPhoneNumber();
    void InsertAfter(ContactNode *newNode);
    ContactNode *GetNext();
    void PrintContactNode();
    ContactNode();
    ContactNode(string initName, string initPhoneNumber);

private:
    /* Declare data members here */
    string contactName;
    string contactPhoneNumber;
    ContactNode *nextNodePtr;
};

/* Define member functions here */
ContactNode::ContactNode()
{
    this->contactName = "";
    this->contactPhoneNumber = "";
    this->nextNodePtr = nullptr;
}

ContactNode::ContactNode(string initName, string initPhoneNumber)
{
    this->contactName = initName;
    this->contactPhoneNumber = initPhoneNumber;
    this->nextNodePtr = nullptr;
}

string ContactNode::GetName()
{
    return contactName;
}

string ContactNode::GetPhoneNumber()
{
    return contactPhoneNumber;
}

void ContactNode::InsertAfter(ContactNode *newNode)
{
    newNode->nextNodePtr = this->nextNodePtr;
    this->nextNodePtr = newNode;
    return;
}

ContactNode *ContactNode::GetNext()
{
    return nextNodePtr;
}

void ContactNode::PrintContactNode()
{
    // output contact info from linked list
    cout << "Name: " << contactName << endl << "Phone Number: " << contactPhoneNumber << endl << endl;  // Output the contact's name and phone number
    return;
}

int main()
{
    /* Type your code here. */
    // Read the name and phone number for three contacts
    // Create three ContactNode objects and use the objects to build a linked list
    // Output the linked list using a loop to call each node's PrintContactNode() method
    string name, phoneNumber;
    ContactNode *head = nullptr;

    for (int i = 0; i < 3; i++)
    {
        int j = i + 1;
        getline(cin, name);
        getline(cin, phoneNumber);
        ContactNode person(name, phoneNumber);

        cout << "Person " << j << ": " << person.GetName() << ", " << person.GetPhoneNumber() << endl; 

        if (i > 0)
        {
            ContactNode *current = head;
            while (current->GetNext()!= nullptr)
            {
                current = current->GetNext();
            }
            current->InsertAfter(&person);
        }
        else
        {
            head = &person;
        }
    }

    // Output the linked list
    ContactNode *current = head;
    for (int i = 0; i < 3; i++)
    {
        current->PrintContactNode();
        current = current->GetNext();
    }

    return 0;
}
