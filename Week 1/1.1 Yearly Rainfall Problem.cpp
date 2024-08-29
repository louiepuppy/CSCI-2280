#include <iostream>
using namespace std;

/*
Problem: Write a program using ARRAYs to accept monthly rainfall of a year
from standard input device, and compute & display average, high, and low 
rainfall of the year. Solution must include arrays and functions.
*/

void showStats(int high, int low, int total, int avg, string highestMonth, string lowestMonth);
void getData(const int MONTHS, string month[], int rain[], int& high, int& low, int& total, int& average, string& highestMonth, string& lowestMonth);

// main module
int main()
{
    const int MONTHS = 12;

    // Months and rainfall arrays
    string month[MONTHS] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    int rain[MONTHS], i, high, low, average, total = 0;
    string highestMonth, lowestMonth;

    // Gather and sort data from the user
    getData(MONTHS, month, rain, high, low, total, average, highestMonth, lowestMonth);

    showStats(high, low, total, average, highestMonth, lowestMonth);

    return 0;
}

// showstats module shows high, low, and average rainfall
void showStats(int high, int low, int total, int average, string highestMonth, string lowestMonth)
{
    cout << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Rainfall Statistics" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~" << endl << endl;
    cout << "Highest rainfall: " << highestMonth << " at " << high << " inches." << endl;
    cout << "Lowest rainfall: " << lowestMonth << " at " << low << " inches." << endl;
    cout << "Average rainfall: " << average << " inches." << endl;
    cout << "Total rainfall: " << total << " inches." << endl;

    return;
}

void getData(const int MONTHS, string month[], int rain[], int& high, int& low, int& total, int& average, string& highestMonth, string& lowestMonth)
{
    int i;

    // Accepting rainfall amounts for each month from user
    for (i = 0; i < MONTHS; i++) 
    {
        cout << "Enter rainfall (in inches) for " << month[i] << ": ";
        cin >> rain[i];
    }

    // Calculating average rainfall
    for (i = 0; i < MONTHS; i++)
    {
        total += rain[i];
        if (rain[i] > high)
        {
            high = rain[i];
            highestMonth = month[i];
        }
        if (rain[i] < low)
        {
            low = rain[i];
            lowestMonth = month[i];
        }
    }

    average = total / MONTHS;
    
    return;
}