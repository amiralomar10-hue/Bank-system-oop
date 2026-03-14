#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
{
private:
	static void PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
	static string _ReadAccountNumber()
	{
		cout << "\nPlease Enter Account Number: ";
		return clsInputValidate<string>::ReadString();
	}
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is not Found, Choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();

		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		PrintClient(Client);
		double Amount;
		cout << "Plase enter whitdraw amount?";
		cin >> Amount;
		cout << "\n\n";
		char ch = 'Y';
		cout << "Are you sure you want perfromthis transaction? y/n? ";
		cin >> ch;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (toupper(ch) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "Client Withdraw Successfully.\n New Account Balance = " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;
			}
		}
		else
			cout << "\nOperation was canelled.\n";
	}

};
