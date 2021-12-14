#include <iostream>
#include <string>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount() //constructor
{
	this->owner = "null";
	this->balance = 0;
}
BankAccount::BankAccount(string owner, int balance)
{
	this->owner = owner;
	this->balance = balance;
}
BankAccount::~BankAccount() //destructor
{
	cout << "Access to " << owner << "'s account has been closed." << endl;
}

void BankAccount::deposit(int amount)
{
	if (amount > 0)
	{
		balance += amount;
		cout << "Thank you for your deposit of $" << amount << "." << "Your new account balance is $" << balance << "." << endl;
	}
	else
	{
		cout << "Please deposit only positive amount to this account." << endl;
	}
}
void BankAccount::withdraw(int amount)
{
	if (amount > 0)
	{
		balance -= amount;
		cout << "Your withdrawal of $" <<amount << " has been processed. Your new balance is $" << balance << "." << endl;
	}
	else
	{
		cout << "Please enter a positive amount to withdraw." << endl;
	}
}
void BankAccount::getBalance() const
{
	cout << "The balance of " << owner << "'s account is: $" << balance << "." << endl;
}
void BankAccount::getOwner() const
{
	cout << "The owner of this account is " << owner << "." << endl;
}