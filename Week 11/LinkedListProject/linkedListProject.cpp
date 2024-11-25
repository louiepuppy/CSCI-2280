#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

/*  Using classes, design an online address book to keep track of the names,
    addresses, phone numbers, and dates of birth of family members, close friends,
    and certain business associates.

    The program should perform the following operations:
i.	Load the data into the address book from the data file.
ii.	Sorts the address book by the last name.
iii.	Search for a person by their last name.
iv.	Print the address, phone number, and date of birth (if it exists) of a given person.
v.	 Print the names of the people whose birthdays are in a given month.
vi.	Print the names of all the people between the two last names.
vii.	Depending on the user’s request, print the names of all family members, friends, or business associates.

Create a link list for the above addressbookType and add the following operations to your program:
1.	Display the addressbook list.
2.	Add or delete a new entry to the addressbook and display the list after adding to or deleting a record from the addressbook list.
3.	Allow the user to save the data in the address book.
*/

void menu(LinkedList &);
void readFromInputFile(LinkedList &);
void addEntry(LinkedList &);
void deleteEntry(LinkedList &);

using namespace std;

int main()
{
    LinkedList addressBook;

    menu(addressBook);

    return 0;
}

void menu(LinkedList &addressBook)
{
    int choice = 99;
    string lastName;
    AddressBookType tempAddr;

    while (choice != 0)
    {
        cout << "~~~Address Book Program~~~" << endl;
        cout << "1. read data from file" << endl;
        cout << "2. sort address book by last name" << endl;
        cout << "3. search for a person by last name" << endl;
        cout << "4. print address/phone number/DOB of a person (by last name)" << endl;
        cout << "5. print names of all people with the same birth month" << endl;
        cout << "6. print names of all people between two last names" << endl;
        cout << "7. print all Family/Friends/Business associates" << endl;
        cout << "8. add new entry" << endl;
        cout << "9. delete entry" << endl;
        cout << "10. save data to file" << endl;
        cout << "0. exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            readFromInputFile(addressBook);
            break;
        case 2:
            addressBook.sortAddressBook();
            cout << "Address book sorted by last name." << endl
                 << endl;
            addressBook.displayList();
            break;
        case 3:
            cout << "Enter the last name of the person to search: ";
            cin >> lastName;
            cout << "Searching for " << lastName << "'s information..." << endl;
            tempAddr = addressBook.searchAddressBook(lastName);
            tempAddr.displayAddressBook();
            break;
        case 4:
            cout << "Enter the last name of the person to print information: ";
            cin >> lastName;
            tempAddr = addressBook.searchAddressBook(lastName);
            cout << "Address: " << tempAddr.getStreetAddress() << endl;
            cout << tempAddr.getCity() << ", " << tempAddr.getState() << " " << tempAddr.getZipCode() << endl;
            cout << "Phone Number: " << tempAddr.getPhoneNumber() << endl;
            cout << "DOB: " << tempAddr.getMonth() << "/" << tempAddr.getDay() << "/" << tempAddr.getYear() << endl
                 << endl;
            break;
        case 5:
            addressBook.findSameBirthMonths();
            break;
        case 6:
            addressBook.findBetweenTwoLastNames();
            break;
        case 7:
            addressBook.printAllRelationshipType();
            break;
        case 8:
            addEntry(addressBook);
            break;
        case 9:
            deleteEntry(addressBook);
            break;
        case 10:
            addressBook.saveToFile();
            break;
        case 0:
            cout << "Exiting..." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}

void readFromInputFile(LinkedList &addressBook)
{
    ifstream inputFile("inputData.txt");

    if (!inputFile.is_open())
    {
        cout << "Error opening input file." << endl;
        return;
    }

    cout << "Reading input file..." << endl;

    string firstName, lastName, streetAddr, city, state, phone, relation;
    int day, month, year, zip;

    while (inputFile >> firstName >> lastName)
    {
        AddressBookType temp;

        // Read all fields for this person
        inputFile >> month >> day >> year;

        // Clear the newline before getline
        inputFile.ignore(1000, '\n');

        // Read the full street address
        getline(inputFile, streetAddr);
        getline(inputFile, city);
        getline(inputFile, state);

        // Read remaining fields
        inputFile >> zip >> phone >> relation;

        // inputFile.ignore(1000, '\n');

        // Set all the fields
        temp.setFirstName(firstName);
        temp.setLastName(lastName);
        temp.setMonth(month);
        temp.setDay(day);
        temp.setYear(year);
        temp.setStreetAddress(streetAddr);
        temp.setCity(city);
        temp.setState(state);
        temp.setZipCode(zip);
        temp.setPhoneNumber(phone);
        temp.setRelationship(relation);

        addressBook.appendNode(temp);
    }

    inputFile.close();
    cout << "Address book loaded successfully." << endl;
}

void addEntry(LinkedList &addressBook)
{
    string firstName, lastName, streetAddr, city, state, phone, relation;
    int day, month, year, zip;

    cout << "Enter new entry information:" << endl;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Enter DOB (MM/DD/YYYY): ";
    cin >> month >> day >> year;
    cout << "Street Address: ";
    cin.ignore();
    getline(cin, streetAddr);
    cout << "City: ";
    getline(cin, city);
    cout << "State: ";
    getline(cin, state);
    cout << "Zip Code: ";
    cin >> zip;
    cout << "Phone Number: ";
    cin >> phone;
    cout << "Relationship: ";
    cin >> relation;

    AddressBookType temp;

    temp.setFirstName(firstName);
    temp.setLastName(lastName);
    temp.setMonth(month);
    temp.setDay(day);
    temp.setYear(year);
    temp.setStreetAddress(streetAddr);
    temp.setCity(city);
    temp.setState(state);
    temp.setZipCode(zip);
    temp.setPhoneNumber(phone);
    temp.setRelationship(relation);

    addressBook.appendNode(temp);
    cout << "New entry added to the address book." << endl;
}

void deleteEntry(LinkedList &addressBook)
{
    string lastName;
    AddressBookType temp;
    cout << "Enter the last name of the person to delete: ";
    cin >> lastName;
    temp = addressBook.searchAddressBook(lastName);
    addressBook.deleteNode(temp);

    cout << "Entry with last name " << lastName << " deleted from the address book." << endl;
}
