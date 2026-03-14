#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsDate.h"
class clsLoginScreen :protected clsScreen
{

private:
    
    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        int count = 3;
        do
        {
            
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << --count << " Trial(s) to login.\n\n";
                if (count==0)
                {
                    cout << "Your are Locked after 3 faild trails\n";
                    return false;
                }
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};


