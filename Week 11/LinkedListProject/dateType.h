#ifndef DATETYPE_H
#define DATETYPE_H

#include "personType.h"
#include <iostream>
using namespace std;

class dateType : public personType
{
private:
    int month;
    int day;
    int year;

public:
    dateType(int month = 1, int day = 1, int year = 1969);
    void setMonth(int month);
    int getMonth();
    void setDay(int day);
    int getDay();
    void setYear(int year);
    int getYear();
    void displayDate();
};

dateType::dateType(int month, int day, int year)
{
    setMonth(month);
    setDay(day);
    setYear(year);
}

void dateType::setMonth(int month)
{
    if (month > 0 && month <= 12){
        this->month = month;
        }
    else
    {
        cout << "Invalid month. Setting month to 1." << endl;
        this->month = 1;
    }
}

int dateType::getMonth()
{
    return month;
}

void dateType::setDay(int day)
{
    if (month == 2)
    {
        if (year % 4 == 0 && (year % 100!= 0 || year % 400 == 0))
        {
            if (day >= 1 && day <= 29)
                this->day = day;
            else
            {
                cout << "Invalid day for February. Setting day to 1." << endl;
                this->day = 1;
            }
        }
        else
        {
            if (day >= 1 && day <= 28)
                this->day = day;
            else
            {
                cout << "Invalid day for February. Setting day to 1." << endl;
                this->day = 1;
            }
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day >= 1 && day <= 30)
            this->day = day;
        else
        {
            cout << "Invalid day for this month. Setting day to 1." << endl;
            this->day = 1;
        }
    }
}

int dateType::getDay()
{
    return day;
}

void dateType::setYear(int year)
{
    this->year = year;
}

int dateType::getYear()
{
    return year;
}

void dateType::displayDate()
{
    cout << month << "/" << day << "/" << year << endl;
}

#endif // DATETYPE_H