#include <iostream>
#include "checkingAccount.h"
#include "savingsAccount.h"

using namespace std;

int main()
{
    checkingAccount c1(1000, 1000.0, 4, 500, 20);
    checkingAccount c2(1001, 2300.0, 4, 500, 20);

    savingsAccount s1(1002, 9300.0, 4);
    savingsAccount s2(1003, 32.0, 4);

    c1.deposit(1000);
    c2.deposit(2300);
    c1.printCheckingInfo();
    c2.printCheckingInfo();

    s1.deposit(800);
    s2.deposit(500);
    s1.printSavingsAccInfo();
    s2.printSavingsAccInfo();

    c1.withdraw(250);
    c2.withdraw(350);
    c1.printCheckingInfo();
    c2.printCheckingInfo();

    s1.withdraw(120);
    s2.withdraw(290);
    s1.printSavingsAccInfo();
    s2.printSavingsAccInfo();

    return 0;
}