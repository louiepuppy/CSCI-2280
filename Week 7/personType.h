#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
using namespace std;

class personType
{
protected:
    string firstName;
    string lastName;
    int age;

public:
    void setFirstName(string firstName);
    string getFirstName();
    void setLastName(string lastName);
    string getLastName();
    void display();
    personType(string firstName = "", string lastName = "", int age = 0);
};

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

void personType::display()
{
    cout << "Name: " << firstName << " " << lastName << endl;
}

personType::personType(string firstName, string lastName, int age)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
}

#endif // PERSONTYPE_H