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

using namespace std;

int main()
{
    LinkedList addressBook;
    AddressBookType addr1;
    ifstream inputFile("inputData.txt");
    
    if (!inputFile.is_open())
    {
        cout << "Error opening input file." << endl;
        return 1;
    }
    // while (!inputFile.eof())
    {
        int intInput;
        string strInput;
        AddressBookType temp;
        inputFile >> strInput;
        temp.setFirstName(strInput);
        inputFile >> strInput;
        temp.setLastName(strInput);
        inputFile >> intInput;
        temp.setDay(intInput);
        inputFile >> intInput;
        temp.setMonth(intInput);
        inputFile >> intInput;
        temp.setYear(intInput);
        getline(inputFile, strInput);
        temp.setStreetAddress(strInput);
        inputFile >> strInput;
        temp.setCity(strInput);
        inputFile >> strInput;
        temp.setState(strInput);
        inputFile >> intInput;
        temp.setZipCode(intInput);
        inputFile >> strInput;
        temp.setPhoneNumber(strInput);
        inputFile >> strInput;
        temp.setRelationship(strInput);
        addressBook.appendNode(temp);
    }
    inputFile.close();
    cout << "Address book loaded successfully." << endl;

    addressBook.displayList();

    addressBook.sortAddressBook();

    cout << "Address book sorted by last name." << endl;
    addressBook.displayList();

    cout << "Searching for Goofy's information..." << endl;
    addr1 = addressBook.searchAddressBook("Goofy");
    addr1.displayAddressBook();
}