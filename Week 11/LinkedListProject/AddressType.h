#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H
#include <iostream>
using namespace std;

class AddressType
{
private:
    string streetAddress;
    string city;
    string state;
    int zipCode;

public:
    AddressType(string streetAddress = "", string city = "", string state = "", int zipCode = 0);
    void setStreetAddress(string);
    string getStreetAddress();
    void setCity(string);
    string getCity();
    void setState(string);
    string getState();
    void setZipCode(int);
    int getZipCode();
    void displayAddress();
};

AddressType::AddressType(string streetAddress, string city, string state, int zipCode)
{
    this->streetAddress = streetAddress;
    this->city = city;
    this->state = state;
    this->zipCode = zipCode;
}

void AddressType::setStreetAddress(string streetAddress)
{
    this->streetAddress = streetAddress;
}

string AddressType::getStreetAddress()
{
    return streetAddress;
}

void AddressType::setCity(string city)
{
    this->city = city;
}

string AddressType::getCity()
{
    return city;
}

void AddressType::setState(string state)
{
    this->state = state;
}

string AddressType::getState()
{
    return state;
}

void AddressType::setZipCode(int zipCode)
{
    this->zipCode = zipCode;
}

int AddressType::getZipCode()
{
    return zipCode;
}

void AddressType::displayAddress()
{
    cout << "Street Address: " << streetAddress << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Zip Code: " << zipCode << endl;
}

#endif // ADDRESSTYPE_H