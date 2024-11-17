#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
using namespace std;

class personType
{
    private: 
        string firstName;
        string lastName;
    
    public:
        void setFirstName(string);
        void setLastName(string);
        string getFirstName() const;
        string getLastName() const;
        string getName() const;
        void display();
        personType(string, string);
        personType();
};

void personType::setFirstName(string f)
{
    firstName = f;
    return;
}

void personType::setLastName(string l)
{
    lastName = l;
    return;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

string personType::getName() const
{
    return firstName + " " + lastName;
}

void personType::display()
{
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    return;
}

personType::personType(string f, string l)
{
    firstName = f;
    lastName = l;
    return;
}

personType::personType()
{
    firstName = "John";
    lastName = "Doe";
    return;
}

#endif