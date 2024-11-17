#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

class bankAccount
{
protected:
    int accountNumber;
    double balance;

public:
    void setAccNum(int);
    void setBalance(double);
    int getAccNum() const;
    double getBalance() const;
    void deposit(double);
    void withdraw(double);
    void printAccInfo() const;
    bankAccount(int, double);
    bankAccount();
};

void bankAccount::setAccNum(int newAccNum)
{
    accountNumber = newAccNum;
}

void bankAccount::setBalance(double newBalance)
{
    balance = newBalance;
}

int bankAccount::getAccNum() const
{
    return accountNumber;
}

double bankAccount::getBalance() const
{
    return balance;
}

void bankAccount::deposit(double amount)
{
    balance += amount;
}

void bankAccount::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
    else
    {
        cout << "Insufficient funds." << endl
             << endl;
    }
}

void bankAccount::printAccInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl
         << endl;
}

bankAccount::bankAccount(int accNum, double initialBalance)
{
    accountNumber = accNum;
    balance = initialBalance;
}

bankAccount::bankAccount()
{
    accountNumber = 0;
    balance = 0.0;
}

#endif