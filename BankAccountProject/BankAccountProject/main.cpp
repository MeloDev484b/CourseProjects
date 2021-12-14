#include <iostream>
#include "BankAccount.h"

using namespace std;

int amount = 0;
string owner = owner;

int main()
{

	BankAccount jimmy ("Jimmy Jimenson", 4380);
	BankAccount henry ("Henry Henrison", 320);
	BankAccount bill ("Bill Billson", 99999);

	jimmy.getBalance();
	jimmy.deposit(200);
	jimmy.getOwner();

	henry.getBalance();
	henry.withdraw(5000);
	henry.getOwner();

	bill.getBalance();
	bill.deposit(-500);
	bill.getOwner();

	return 0;
}