#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
bool checkAlpha(string str) {

	bool retVal = false;
	while (retVal == false)
	{


		for (int i = 0; i < str.size(); i++) {
			if (isalpha(str[i]) == 0) {

				retVal = false;
				cout << "Input must only contain letters\n";

				break;

			}
			else {

				retVal = true;
				cout << "all good\n";
			}
		}
		return retVal;
	}
}
class Person
{
protected:
	//Attributes
	int id;
	string first_name, last_name, password;
public:
	//constructor
	Person() {
		this->id = 0;
	}
	Person(int id, string first_name, string last_name, string password) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->id = id;
		this->password = password;
	}

	//setterrs
	void set_id(int id)
	{
		this->id = id;
	}
	void set_first_name()
	{
		string first_name;
		cout << "Enter your name: ";
		cin >> first_name;
		bool ch = false;
		while (ch == false) {
			if (first_name.length() >= 4 && first_name.length() <= 20 && checkAlpha(first_name) != 0) {
				this->first_name = first_name;
				ch = true;
			}
			else {
				cout << "error :Name must be alphabetic and between 5 and 20 characters.\nEnter your name: " << endl;
				cin >> first_name;
				break;

			}
		}



	}
	void set_last_name()
	{
		string last_name;
		cout << "Enter your name: ";
		cin >> last_name;
		bool ch = false;
		while (ch == false) {
			if (last_name.length() >= 4 && last_name.length() <= 20 && checkAlpha(last_name) != 0) {
				this->last_name = last_name;
				ch = true;
			}
			else {
				cout << "error :Name must be alphabetic and between 5 and 20 characters.\nEnter your name: " << endl;
				cin >> last_name;
				break;

			}
		}

	}
	void set_password()
	{
		string password;
		cout << "please enter password: ";
		cin >> password;
		bool ch = false;
		while (ch==false)
		{
			if (password.length() < 8) {
				cout << "password should be more than 8 char.\n please enter correct password: ";
				cin >> password;

			}
			else {
				this->password = password;
				ch = true;
			}
		}

		}


	//getters
	string get_first_name() {
		return this->first_name;
	}
	string get_last_name() {
		return this->last_name;
	}
	string get_password() {
		return this->password;
	}
	int get_id() {
		return this->id;
	}
	virtual void displayRole() const = 0;


};

class Client :public Person {
	double balance;
public:
	Client() {
		this->balance = 1500;
	}
	Client(string first_name, string last_name, int id, string password, double balance) :Person(id, first_name, last_name, password)
	{
		this->balance = balance;
	}
	void set_balance(double balance) {
		this->balance = balance;
	}


	double get_balance() const {
		return this->balance;
	}

	/*void ch_name(string first_name, string last_name) {
		bool found = false;
		int b;
		cout << "Enter the first name\n";
		cin >> first_name;

		for (char ch : first_name)
			if (isdigit(ch)) {
				found = true;
			}
		if (found == true) {
			cout << "It must be only litter\n";
			cout << "Enter the first name\n";
			cin >> first_name;
		}
		cout << "Enter the last name\n";
		cin >> last_name;

		for (char ch : last_name)
			if (isdigit(ch)) {
				found = true;
			}

		if (found == true)cout << "It must be only litter\n";

		b = first_name.length() + last_name.length();
		if (b < 5 || b>20)
		{
			cout << "Enter the name from 5 to 20 character\n";
		}

	}*/

	/*void set_password(string password) {
		cout << "Enter the password\n";
		cin >> password;
		if (password.length() < 8 || password.length() > 20)
			cout << "Enter the password from 8 to 20 character\n";

	}*/


	void name() {
		cout << "Name : " << get_first_name() << " " << get_last_name() << endl;
		cout << "Id   : " << get_id() << endl;
		cout << "Balane : " << balance << endl;

	}

	void deposit(double amount) {
		balance += amount;
		cout << "The operation was completed successfuly\n";
		cout << "Your current balance : " << balance << endl;
	}

	void withdraw(double amount) {
		if (amount <= balance)
		{
			balance -= amount;
			cout << "The operation was completed successfuly\n";
			cout << "Your current balance : " << balance << endl;
		}
		else
		{
			cout << "your balance is insufficient\n";
		}
	}


	void transferTo(Client c2, double amount) {
		if (amount <= balance)
		{
			balance -= amount;
			c2.deposit(amount);
			cout << "The operation was completed successfuly\n";
			cout << "Your current balance : " << balance << endl;
		}
		else
		{
			cout << "your balance is insufficient\n";
		}
	}
	void recipient(Client c, double amount) {
		balance += amount;
		c.withdraw(amount);
		cout << "The operation was completed successfuly\n";
		cout << "Your current balance : " << balance << endl;
	}
	void displayRole() const override {
		cout << "Role: Cleint" << endl;
	}
};
class BankAccount {
private:
	int accountNumber;
	string accountHolder;
	double balance;

public:

	BankAccount(int accNumber, string accHolder, double initialBalance) {
		accountNumber = accNumber;
		accountHolder = accHolder;
		balance = initialBalance;
	}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Successfully deposited $" << amount << endl;
		}
		else {
			cout << "Invalid deposit amount!" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "Successfully withdrew $" << amount << endl;
		}
		else {
			cout << "Insufficient balance or invalid amount!" << endl;
		}
	}

	void displayAccountDetails() const {
		cout << "Account Number: " << accountNumber << endl;
		cout << "Account Holder: " << accountHolder << endl;
		cout << "Balance: $" << balance << endl;
	}

	// Getter for account number
	int getAccountNumber() const {
		return accountNumber;
	}
};



class Admin : public Person {
private:
	vector<BankAccount> accounts;

public:
	Admin(string name, int id) : Person(id, first_name, last_name,password) {}

	void displayRole() const override {
		cout << "Role: Admin" << endl;
	}

	void createAccount(int accountNumber, string accountHolder, double initialBalance) {
		BankAccount newAccount(accountNumber, accountHolder, initialBalance);
		accounts.push_back(newAccount);
		cout << "Account created successfully!" << endl;
	}

	void deleteAccount() {
		bool repeat = false;
		int account_num;
		cout << "please enter acc.num";
		cin >> account_num;
		while (repeat == false) {
			for (auto it = accounts.begin(); it != accounts.end(); ++it) {
				if (it->getAccountNumber() == account_num) {
					accounts.erase(it);
					cout << "Account deleted successfully!" << endl;
					repeat = true;
					return;
				}
			}
			cout << "Account not found!\n please enter valid ID" << endl;
			cin >> account_num;

		}
	}

	void viewAllAccounts() const {

		for (const auto& account : accounts) {
			displayRole();
			account.displayAccountDetails();
			cout << "-----------------" << endl;
		}
	}
};


