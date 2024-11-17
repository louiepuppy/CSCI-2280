#ifndef DATETYPE_H
#define DATETYPE_H

#include <iostream>
using namespace std;

class dateType
{
    private:
        int day;
        int month;
        int year;
        
    public:
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        string getDate();
        void printDate() const;
        dateType(int, int, int);
        dateType();
};

void dateType::setDay(int d)
{
    if (d >= 1 && d <= 31)
        day = d;
    else {
        cout << "Invalid day. Setting day to 1." << endl;
        day = 1;
    }
}

void dateType::setMonth(int m)
{
    if (m >= 1 && m <= 12)
        month = m;
    else
        cout << "Invalid month. Setting month to 1." << endl;
}

void dateType::setYear(int y)
{
    year = y;
}

int dateType::getDay() const
{
    return day;
}

int dateType::getMonth() const
{
    return month;
}

int dateType::getYear() const
{
    return year;
}

void dateType::printDate() const
{
    cout << month << "/" << day << "/" << year << endl;
    return;
}

string dateType::getDate()
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

dateType::dateType(int d, int m, int y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
    return;
}

dateType::dateType()
{
    day = 1;
    month = 1;
    year = 1969;
    return;
}

#endif // DATETYPE_H