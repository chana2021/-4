#pragma once
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
	double getBalance();//return balance

	Account(); //.Constructors/defult
	~Account();//destructor
	Account(int myAccountNumber, int myCode,string myMail);//Constructors
	friend istream& operator>>(istream& is, Account r);
	void withdraw(int nis);//tAKE MANY
	void deposit(int nis);//put many till 10000
	
	static double  getSumWithdraw();//scum checkout many
	static double getSumDeposit();//scum chek put
};
//int Account::sumDeposit;
//int Account::sumWithdraw;