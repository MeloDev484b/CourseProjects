#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

using namespace std;

class BankAccount
{
	public:
		BankAccount(); //constructor
		BankAccount(string owner, int balance);
		~BankAccount(); //destructor
		void deposit(int amount);
		void withdraw(int amount);
		void getBalance() const;
		void getOwner() const;
	private:
		string owner;
		int balance;
		int amount;
};


#endif
