#ifndef DOCTORTPYE_H
#define DOCTORTPYE_H

#include <iostream>
#include "personType.h"
using namespace std;

class doctorType : public personType
{
protected:
    string specialty;

public:
    void setSpecialty(string specialty);
    string getSpecialty();
    void display();
    doctorType(string specialty);
    doctorType();
};

void doctorType::setSpecialty(string specialty)
{
    this->specialty = specialty;
}

string doctorType::getSpecialty()
{
    return specialty;
}

void doctorType::display()
{
    personType::display();
    cout << "Specialty: " << specialty << endl;
}

doctorType::doctorType(string specialty) : personType(firstName, lastName)
{
    this->specialty = specialty;
}

doctorType::doctorType() : personType()
{
    specialty = "";
}

#endif // DOCTORTPYE_H