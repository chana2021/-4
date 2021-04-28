// chana cohen 324245935
//mavo lmadae amachshev
//targil 4 
//
#include <iostream>
#include "Clock.h"
#include "Account.h"
#include<string>
using namespace std;
enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: " << endl;;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	cout << "please enter the code: " << endl;;
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: " << endl;;
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}
int main()
{
	Clock c(8);
	Account bank[2];//
	cout << "enter account number, code and email for 10 accounts:\n";
	for (int i = 0; i < 2; i++)//
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 2, c);//
			break;
		case withdraw:cashWithdraw(bank, 2, c);//
			break;
		case deposit:cashDeposit(bank, 2, c);//
			break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);

		}
		ac = menu();
	}
	return 0;
}