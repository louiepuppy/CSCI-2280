#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Consider the declaration of the struct houseType given below:

struct houseType
{
    string style;
    int numBedrooms;
    int numBathrooms;
    int numCarsGarage;
    int yearBuilt;
    int finishedSquareFootage;
    double price;
    double tax;
};

/*
Using houseType using structure, write a complete program with the following functions 
(you can include or exclude functions of your choice):
*/

void print(vector<houseType>&); // display output on monitor
void print(vector<houseType>&, ofstream&); // display in an output file
void readData(houseType&); // read one record of data from keyboard
void readData(vector<houseType>&, ifstream&); // read a set of data from data file
bool compareHouses(vector<houseType>&, houseType, houseType);
/*
compare two houses if at least finished square footages and price are
same then both houses are identical otherwise they are different
*/

int main()
{
    ifstream in("./data.txt"); // input file
    ofstream out("./output.txt"); // output file

    vector<houseType> houses; // vector of houses with their details
    houseType house; // for manual data entry
    houseType house1, house2; // for comparison
    int choice = 9;

    if (!in)
    {
        cout << "File does not exist." << endl;
        return 1;
    }

    if (!in.is_open())
    {
        cout << "1. Error opening input file." << endl;
        return 1;
    }
    else if (!out.is_open())
    {
        cout << "2. Error opening output file." << endl;
        return 1;
    }


    while (choice != 0)
    {
        cout << endl << endl;

        cout << "1. Enter house details." << endl;
        cout << "2. Read house details from file." << endl;
        cout << "3. Print details of all houses." << endl;
        cout << "4. Write details of all houses to an output file." << endl;
        cout << "5. Compare two houses." << endl;
        cout << "0. Exit." << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                readData(house);
                houses.push_back(house);
                break;
            case 2:
                readData(houses, in);
                break;
            case 3:
                print(houses);
                break;
            case 4:
                print(houses, out);
                break;
            case 5:
                compareHouses(houses, house1, house2);
                break;
            case 0:
                return 0;
                break;
        }
    }

    in.close();
    out.close();

    return 0;
}

void print(vector<houseType>& houses)
{
    for (int i = 0; i < houses.size(); i++)
    {
        cout << "Style: " << houses[i].style << endl;
        cout << "Number of bedrooms: " << houses[i].numBedrooms << endl;
        cout << "Number of bathrooms: " << houses[i].numBathrooms << endl;
        cout << "Number of cars garage: " << houses[i].numCarsGarage << endl;
        cout << "Year built: " << houses[i].yearBuilt << endl;
        cout << "Finished square footage: " << houses[i].finishedSquareFootage << endl;
        cout << "Price: $" << houses[i].price << endl;
        cout << "Tax: $" << houses[i].tax << endl;
        cout << "-----------------------------" << endl;
    }

    return;
}

void print(vector<houseType>& houses, ofstream& out)
{
    

    for (int i = 0; i < houses.size(); i++)
    {
        cout << left << setw(20) << houses[i].style << setw(20) << houses[i].numBedrooms << setw(20) << houses[i].numBathrooms; 
        cout << left << houses[i].numCarsGarage << setw(20) << houses[i].yearBuilt << setw(20) << houses[i].finishedSquareFootage;
        cout << left << houses[i].price << houses[i].tax << endl;
        
    }

    return;
}

void readData(houseType& house)
{
    int choice = 1;

    while (choice != 0)
    {
        cout << "Enter style of house: ";
        cin >> house.style;
        cout << "Enter number of bedrooms: ";
        cin >> house.numBedrooms;
        cout << "Enter number of bathrooms: ";
        cin >> house.numBathrooms;
        cout << "Enter number of cars garage: ";
        cin >> house.numCarsGarage;
        cout << "Enter year built: ";
        cin >> house.yearBuilt;
        cout << "Enter finished square footage: ";
        cin >> house.finishedSquareFootage;
        cout << "Enter price: $";
        cin >> house.price;
        cout << "Enter tax: $";
        cin >> house.tax;

        cout << endl << "-----------------------------" << endl;

        cout << "Enter 0 to exit, any other number to continue: ";
        cin >> choice;
        cout << endl << "-----------------------------" << endl;
    }

    return;
}

void readData(vector<houseType>& houses, ifstream& in)
{
    if (!in.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    while (!in.eof())
    {
        houseType newHouse;
        in >> newHouse.style >> newHouse.numBedrooms >> newHouse.numBathrooms >> newHouse.numCarsGarage;
        in >> newHouse.yearBuilt >> newHouse.finishedSquareFootage >> newHouse.price >> newHouse.tax;
        if (!in.eof())
            houses.push_back(newHouse);
    }

    return;

}

bool compareHouses(vector<houseType>& houses, houseType house1, houseType house2)
{
    int choice;

    // display all houses for the user to choose from
    for (int i = 0; i < houses.size(); i++)
    {
        cout << i + 1 << ". " << "Style: " << houses[i].style << ", Bedrooms: " << houses[i].numBedrooms << ", Bathrooms: ";
        cout << houses[i].numBathrooms << ", Cars Garage: " << houses[i].numCarsGarage << ", Year Built: " << houses[i].yearBuilt << endl;
    }

    cout << endl << "-----------------------------" << endl;
    cout << "Pick the first house: ";
    cin >> choice;
    house1 = houses[choice - 1];

    cout << "Pick the second house: ";
    cin >> choice;
    house2 = houses[choice - 1];

    cout << endl << endl;

    cout << "House 1: " << "Style: " << house1.style << ", Bedrooms: " << house1.numBedrooms << ", Bathrooms: ";
    cout << house1.numBathrooms << ", Cars Garage: " << house1.numCarsGarage << ", Year Built: " << house1.yearBuilt << endl;

    cout << "House 2: " << "Style: " << house2.style << ", Bedrooms: " << house2.numBedrooms << ", Bathrooms: ";
    cout << house2.numBathrooms << ", Cars Garage: " << house2.numCarsGarage << ", Year Built: " << house2.yearBuilt << endl;

    cout << endl << endl;

    if (house1.finishedSquareFootage == house2.finishedSquareFootage && house1.price == house2.price)
    {
        cout << "Houses are identical.";
        return true;
    }
    else
    {
        cout << "Houses are different.";
        return false;
    }
}
