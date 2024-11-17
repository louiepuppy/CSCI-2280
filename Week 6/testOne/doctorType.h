#ifndef DOCTORTYPE_H
#define DOCTORTYPE_H

#include <iostream>
#include "personType.h"
using namespace std;

class doctorType final : public personType
{
    private: 
        string specialization;

    public:
        void setSpecialization(string);
        string getSpecialization();
        void displayDoctorInfo();
        doctorType(string, string, string);
        doctorType();
};

void doctorType::setSpecialization(string s)
{
    specialization = s;
    return;
}

string doctorType::getSpecialization()
{
    return specialization;
}

void doctorType::displayDoctorInfo()
{
    display();
    cout << "Specialization: " << specialization << endl;
    return;
}

doctorType::doctorType(string f, string l, string s) : personType(f, l)
{
    specialization = s;
    return;
}

doctorType::doctorType() : personType()
{
    specialization = "General Practitioner";
    return;
}

#endif