#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H
#include <iostream>
#include <fstream>
#include "dateType.h"

using namespace std;

class AddressBookType : public dateType
{
public:
    AddressBookType() {}
    void displayAddressBook();
};

void AddressBookType::displayAddressBook()
{
    cout << getFirstName() << " " << getLastName() << endl;
    cout << "DOB: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
    cout << "Address: " << getStreetAddress() << endl;
    cout << "City: " << getCity() << endl;
    cout << "State: " << getState() << endl;
    cout << "Zip Code: " << getZipCode() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Relationship: " << getRelationship() << endl
         << endl;
}

#endif // ADDRESSBOOKTYPE_H