#include "Account.h"
#include <cstring>
#include<string>
int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;

int Account:: getAccountNumber() { return accountNumber; }//return accountNumber
int Account:: getCode() { return code; }//return code
int Account::getBalance() { return balance; }//return balance
Account:: Account() {//defult
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail = "";

}
string Account::getMail() { return mail; }
Account:: ~Account() {
	accountNumber=0;
	code = 0;
	balance = 0;
	mail = "";
}
Account::Account(int myAccountNumber, int myCode, string myMail) {//bone
	accountNumber = myAccountNumber;
	code = myCode;
	mail = myMail;
	balance =0;
}
istream& operator>>(istream& is, Account &r) {//koler and bodek if good

	is >> r.accountNumber;
	is >> r.code;
	is >> r.mail;
	r.balance = 0;
	
	if ((r.code > 9999)|| (r.code < 1000))
		throw "ERROR: code must be of 4 digits!";
	//if ((r.code % 10) == 0)
	//	throw "ERROR: wrong code!";
	if (r.mail.find('\t') != -1)
		throw "ERROR: wrong email! ";
	if (r.mail.find('@') == -1)
		throw "ERROR: email must contain @!";//mast be @
	if ((r.mail.find(".com") == -1) && (r.mail.find(".co.il") == -1))
		throw "ERROR: email must end at.com or .co.il!";//not mail good
	return is;

}
 void Account:: withdraw(int nis) {//take many till 2500
	 if ((balance - nis) < -6000)//error
		 throw 4;
	 if (nis > 2500)//mastnt more minus 6000
		 throw 3;

	 balance -= nis;
	sumWithdraw += nis;
		


 }
 void Account:: deposit(int nis)//put many till 10000
 {
	 if (nis > 10000)
		 throw 5;
	 else {
		 balance += nis;
		 sumDeposit += nis;
	 }
		

 }
  int Account:: getSumWithdraw()//scum checkout many
 {
	
	 return sumWithdraw;
 }
  int Account:: getSumDeposit()//scum chek put{
 {
	 
	 return sumDeposit;
 }


