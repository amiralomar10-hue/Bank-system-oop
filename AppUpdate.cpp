#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsString.h"
using namespace std;
void ReadClientInfo(clsBankClient&Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}
void UpdateClient()
{
	cout << "\nPlease Enter client Account Number: ";
	string AccountNumber;
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();
	cout << "\n\nUpdate Client Info:";
	cout << "\n____\n";


	ReadClientInfo(Client);
	clsBankClient::enSaveResults SaveResult;
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:

	//	Client.Print();
		break;
	case clsBankClient::enSaveResults::svFaildEmptyObject:
		cout << "\nError account was not saved because it's Empty";
		break;
	}
}
	int main()
	{
		UpdateClient();
	}


