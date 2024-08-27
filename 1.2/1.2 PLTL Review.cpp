#include <iostream>
#include <fstream>
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

void print(houseType[]); // display output on monitor
void print(houseType[], ofstream&); // display in an output file
void readData(houseType&); // read one record of data from keyboard
void readData(houseType[], int); // read a set of data from data file
bool compareHouses(houseType, houseType);
/*
compare two houses if at least finished square footages and price are
same then both houses are identical otherwise they are different
*/

int main()
{
    

    return 0;
}

void print(houseType[])
{

}

void print(houseType[], ofstream&)
{

}

void readData(houseType&)
{

}

void readData(houseType[], int)
{

}

bool compareHouses(houseType, houseType)
{

}
