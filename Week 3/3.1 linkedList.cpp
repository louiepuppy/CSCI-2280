#include <iostream>
#include <string>
using namespace std;

class ContactNode
{
public:
    string GetName();
    string GetPhoneNumber();
    void InsertAfter(ContactNode *newNode);
    ContactNode *GetNext();
    void PrintContactNode();
    ContactNode(string initName, string initPhoneNumber);

private:
    string contactName;
    string contactPhoneNumber;
    ContactNode *nextNodePtr;
};

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
}

ContactNode *ContactNode::GetNext()
{
    return nextNodePtr;
}

void ContactNode::PrintContactNode()
{
    cout << "Name: " << contactName << endl
         << "Phone Number: " << contactPhoneNumber << endl << endl;
}

int main()
{
    string name, phoneNumber;

    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode *head = new ContactNode(name, phoneNumber);

    ContactNode *current = head;

    for (int i = 1; i < 3; ++i)
    {
        getline(cin, name);
        getline(cin, phoneNumber);
        ContactNode *newNode = new ContactNode(name, phoneNumber);

        current->InsertAfter(newNode);
        current = newNode;
    }

    cout << "Outputting linked list:" << endl;
    current = head;

    while (current != nullptr)
    {
        current = current->GetNext();
        current->PrintContactNode();
    }

    current = head;
    while (current != nullptr)
    {
        ContactNode *temp = current->GetNext();

        delete current;
        current = temp;
    }

    return 0;
}
