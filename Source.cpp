// chana cohen 324245935
//mavo lmadae amachshev
//targil 4 
//like bank take muny put many
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
	cout << "enter 2 to deposit money" << endl;//put many no mor 10000
	cout << "enter 3 to withdraw money" << endl;//take many no more 2500
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
	cout << "please enter account number:" << endl;;
	cin >> number;
	//int i = 0;
	//while (i <= size && bank[i].getAccountNumber() != number)
	//	i++;
	int mis = size;
	for (int i = 0; i < size; i++) {
		if (bank[i].getAccountNumber() == number)
			mis = i;
	}
	if (mis == size)
		throw 1;//throw
	cout << "please enter the code:"<<endl;
	cin >> code;
	if (bank[mis].getCode() == code)
		return mis;
	else
		throw 2;//throw
}

void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	
	switch (ac)
	{
	case balance: cout << "balance: " << a.getBalance() <<"\t" << "account #: " << a.getAccountNumber() <<endl;
		break;
	case deposit:
	case withdraw: cout << "new balance: " << a.getBalance() << "\t" << "account #: " << a.getAccountNumber() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() <<endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() <<endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i;
	i = findAccount(bank, size);
	//catch(const char* msg){
	//	cout << c << '\t' << msg << endl;
	//}
	c += 20;
	printTransaction(bank[i], balance, c);
}

void cashDeposit(Account* bank, int size, Clock& c)
{
	int i;
	i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check:"<<endl;
	cin >> amount;
	
	bank[i].deposit(amount);
	
	c += 30;
	printTransaction(bank[i], deposit, c);
}



void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i;
	i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: " << endl;
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}

int main()
{
	Clock c(8);
	Account bank[10];//
	cout << "enter account number, code and email for 10 accounts:\n";
	cout << endl;
	for (int i = 0; i < 10; i++)//
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg << endl;
			i--;
		}
		
		
	}

		action ac = menu();
		
		while (ac)
		{
			cout << endl;
			try {
				switch (ac)
				{
				case balance: getBalance(bank, 10, c);//get balance
					break;
				case deposit:cashDeposit(bank, 10, c);//put many
					break;
				case withdraw:cashWithdraw(bank, 10, c);//take many
					break;
				case sumDeposit:c += 60;
					printTransaction(bank[0], sumDeposit, c);
					break;
				case sumWithdraw:c += 60;
					printTransaction(bank[0], sumWithdraw, c);

				}
				

			}
			catch (int a) {
				switch (a) {
				case 1:cout << c << '\t' << " ERROR: no such account number!" << endl;
					break;
				case 2:cout << c << '\t' << "ERROR: wrong code!" << endl;
					break;
				case 3:cout << c << '\t' << "ERROR: cannot withdraw more than 2500 NIS! " << endl;
					break;
				case 4:cout << c << '\t' << "ERROR: cannot have less than - 6000 NIS!" << endl;
					break;
				case 5:cout << c << '\t' << "ERROR: cannot deposit more than 10000 NIS!" << endl;
					break;

				}

			}
			ac = menu();
		}
	return 0;
}