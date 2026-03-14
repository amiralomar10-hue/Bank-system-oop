#include <iostream> 
#include "clsBankClient.h" 
#include"clsInputValidate.h"
void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is not Found, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();
    cout << "\nAre you sure you want to delete this client y/n? ";
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {


        if (Client.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            Client.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }
}


int main()

{
    DeleteClient();
    system("pause>0");
    return 0;
}