#include<iostream>
#include"person.h"



using namespace std;
int main() {
	Client c1,c2;

	cout << "Welcome to the National Bank\n\n";

	string first_name, last_name;
	c1.ch_name(first_name, last_name);
	cout << "Enter id \n";

	int i;
	cin >> i;
	c1.set_id(i);

	c1.get_password();

	cout << "1- Deposit\n";
	cout << "2- Withdraw\n";
	cout << "3- Transfer To\n";
	cout << "4- Balance Check\n";

	cout << "Enter the operation number\n";
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "Enter the balance\n ";
		double amount;
		cin >> amount;
		c1.deposit(amount);
	}

	else if (n == 2)
	{
		cout << "Enter the balance\n ";
		double amount;
		cin >> amount;
		c1.withdraw(amount);
	}

	else if (n == 3)
	{
		cout << "Enter the account and balance\n ";
		double amount;
		cin >> amount;
		c1.transferTo(c2, amount);
	}

	else if (n == 4)
	{
		c1.name();
	}
	Admin admin1("Mariam", 402);
	admin1.createAccount(1001, "Amaar", 500.0);
	

	admin1.viewAllAccounts();

	admin1.deleteAccount();
	admin1.viewAllAccounts();
}
	
