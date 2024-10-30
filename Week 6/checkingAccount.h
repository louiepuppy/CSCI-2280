#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include "bankAccount.h"
using namespace std;

class checkingAccount : public bankAccount
{
private:
    double interestRate;
    double minBal;
    double serviceCharge;

public:
    void setInterestRate(double ir);
    double getInterestRate() const;
    void setMinBal(double mb);
    double getMinBal() const;
    void setServiceCharge(double sc);
    double getServiceCharge() const;
    double postInterestRate() const;
    bool verifyBal() const;
    void writeCheck(double);
    void withdraw(double);
    void printCheckingInfo() const;
    checkingAccount(int id, double bal, double ir, double mb, double sc);
    checkingAccount();
};

void checkingAccount::setInterestRate(double ir)
{
    interestRate = ir;
}

double checkingAccount::getInterestRate() const
{
    return interestRate;
}

void checkingAccount::setMinBal(double mb)
{
    minBal = mb;
}

double checkingAccount::getMinBal() const
{
    return minBal;
}

void checkingAccount::setServiceCharge(double sc)
{
    serviceCharge = sc;
}

double checkingAccount::getServiceCharge() const
{
    return serviceCharge;
}

double checkingAccount::postInterestRate() const
{
    return balance + balance * (interestRate / 100);
}

bool checkingAccount::verifyBal() const
{
    return balance >= minBal;
}

void checkingAccount::writeCheck(double amount)
{
    if (verifyBal())
    {
        if (balance - amount >= minBal)
        {
            balance -= amount;
            cout << "Check written successfully." << endl
                 << endl;
        }
        else
        {
            cout << "Insufficient balance for check." << endl
                 << endl;
        }
    }
    else
    {
        cout << "Account balance is below minimum balance." << endl
             << endl;
    }
}

void checkingAccount::withdraw(double amount)
{
    if (verifyBal())
    {
        if (balance - amount >= minBal)
        {
            balance -= amount;
            cout << "Withdrawal successful." << endl
                 << endl;
        }
        else
        {
            cout << "Insufficient balance for withdrawal." << endl
                 << endl;
        }
    }
    else
    {
        cout << "Account balance is below minimum balance." << endl
             << endl;
    }
}

void checkingAccount::printCheckingInfo() const
{
    cout << "Checking Account ID: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Minimum Balance: $" << minBal << endl;
    cout << "Service Charge: $" << serviceCharge << endl;
    cout << "Total Interest Earned: $" << postInterestRate() - balance << endl;
    cout << "Total amount: $" << postInterestRate() << endl;
    cout << "Current Account Status: ";
    if (verifyBal())
        cout << "Active" << endl;
    else
        cout << "Inactive" << endl;
    cout << endl;
}

checkingAccount::checkingAccount(int id, double bal, double ir, double mb, double sc)
{
    accountNumber = id;
    balance = bal;
    interestRate = ir;
    minBal = mb;
    serviceCharge = sc;
}

checkingAccount::checkingAccount()
{
    accountNumber = 0;
    balance = 0.0;
    interestRate = 0.0;
    minBal = 0.0;
    serviceCharge = 0.0;
}

#endif