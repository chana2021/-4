#pragma once
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<string>
using namespace std;

class Account
{
	int accountNumber;//number of account
	int code;
	double balance;//have many
	string mail;
	
public:
	static int  sumDeposit;//mone scum all afkada machaha
	static int sumWithdraw;//mone scum all chackout
	int getAccountNumber();//return accountNumber
	int getCode();//return code
	int getBalance();//return balance
	string getMail();//return mail
	Account(); //.Constructors/defult
	~Account();//destructor
	Account(int myAccountNumber, int myCode,string myMail);//Constructors
	friend istream& operator>>(istream& is, Account& r);
	void withdraw(int nis);//tAKE MANY
	void deposit(int nis);//put many till 10000
	
	static int  getSumWithdraw();//scum checkout many
	static int getSumDeposit();//scum chek put
};
//int Account::sumDeposit;
//int Account::sumWithdraw;