#include "Account.h"
#include <cstring>
#include<string>
int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;

int Account:: getAccountNumber() { return accountNumber; }//return accountNumber
int Account:: getCode() { return code; }//return code
double Account::getBalance() { return balance; }//return balance
Account:: Account() {//defult
	accountNumber = 0;
	code = 0;
	balance = 0;
	mail.clear();

}
Account:: ~Account() {
	accountNumber=0;
	code = 0;
	balance = 0;
	mail.clear();
}
Account::Account(int myAccountNumber, int myCode, string myMail) {
	accountNumber = myAccountNumber;

	if ((myCode > 9999) || ((myCode % 10) == 0)||(myCode<1000)){
		cout << "ERROR: wrong code!" << endl;
	}
	else
		code = myCode;
	balance =0;
	//while (myMail) {

	//}
	mail = myMail;
}
istream& operator>>(istream& is, Account r) {

	is >> r.accountNumber;

	is >> r.code;
	if ((r.code > 9999) || ((r.code % 10) == 0) || (r.code < 1000))
		cout << "ERROR: wrong code!" << endl;
	is >> r.mail;
	r.balance = 0;
	return is;

}
 void Account:: withdraw(int nis) {//take many till 2500
	 if (nis > 25000)//error
		 cout << "ERROR: cannot withdraw more than 2500 NIS!" << endl;
	 else {
		 if ((balance - nis) <-6000)//mastnt more minus 6000
			 cout << "ERROR: cannot have less than - 6000 NIS!" << endl;
		 else {
			 balance -= nis;
			 sumWithdraw += nis;
		 }
			 
	 }


 }
 void Account:: deposit(int nis)//put many till 10000
 {
	 if (nis > 1000)
		 cout << "ERROR: cannot deposit more than 10000 NIS!" << endl;
	 else {
		 balance += nis;
		 sumDeposit += nis;
	 }
		

 }
  double Account:: getSumWithdraw()//scum checkout many
 {
	
	 return sumWithdraw;
 }
  double Account:: getSumDeposit()//scum chek put{
 {
	 ;
	 return sumDeposit;
 }


