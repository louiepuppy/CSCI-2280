#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include "bankAccount.h"

using namespace std;

class savingsAccount : public bankAccount
{
private:
    double interestRate;

public:
    void setInterestRate(double);
    double getInterestRate();
    double postInterestRate();
    void withdraw(double);
    void printSavingsAccInfo();
    savingsAccount(int, double, double);
    savingsAccount();
};

void savingsAccount::setInterestRate(double r)
{
    interestRate = r;
}

double savingsAccount::getInterestRate()
{
    return interestRate;
}

double savingsAccount::postInterestRate()
{
    return balance + balance * (interestRate / 100);
}

void savingsAccount::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Insufficient funds." << endl
             << endl;
    }
}

void savingsAccount::printSavingsAccInfo()
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Total Interest Earned: $" << postInterestRate() - balance << endl;
    cout << "Total amount: $" << postInterestRate() << endl
         << endl;
}

savingsAccount::savingsAccount(int accNum, double initialBalance, double interest) : bankAccount(accNum, initialBalance)
{
    interestRate = interest;
}

#endif