#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include "AddressType.h"
#include <iostream>
using namespace std;

class personType : public AddressType
{
protected:
    string firstName;
    string lastName;
    int age;
    string phoneNumber;
    string relationship;

public:
    personType(string firstName = "", string lastName = "", int age = 0, string phoneNumber = "", string relationship = "");
    void setFirstName(string firstName);
    string getFirstName();
    void setLastName(string lastName);
    string getLastName();
    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber();
    void setRelationship(string relationship);
    string getRelationship();
    void displayPerson();
};

personType::personType(string firstName, string lastName, int age, string phoneNumber, string relationship)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->phoneNumber = phoneNumber;
    this->relationship = relationship;
}

void personType::setFirstName(string firstName)
{
    this->firstName = firstName;
}

string personType::getFirstName()
{
    return firstName;
}

void personType::setLastName(string lastName)
{
    this->lastName = lastName;
}

string personType::getLastName()
{
    return lastName;
}

void personType::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

string personType::getPhoneNumber()
{
    return phoneNumber;
}

void personType::setRelationship(string relationship)
{
    this->relationship = relationship;
}

string personType::getRelationship()
{
    return relationship;
}

void personType::displayPerson()
{
    cout << "Name: " << firstName << " " << lastName << endl;
}

#endif // PERSONTYPE_H