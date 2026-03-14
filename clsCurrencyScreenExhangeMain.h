#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include <iomanip>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyScreenExhangeMain : protected clsScreen
{
	enum enCurrencyScreenExhangeMenueOptions {
		eListCurrencies = 1, eFindCrrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short ReadManageCurrenciesMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate<int>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}




	static void _PerformManageCurrenciesMenueOption(enCurrencyScreenExhangeMenueOptions ManageUsersMenueOption)
	{

		switch (ManageUsersMenueOption)
		{
		case enCurrencyScreenExhangeMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enCurrencyScreenExhangeMenueOptions::eFindCrrency:
		{
			system("cls");

			_ShowFindCurrencyScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enCurrencyScreenExhangeMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enCurrencyScreenExhangeMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToManageUsersMenue();
			break;
		}

		case enCurrencyScreenExhangeMenueOptions::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}

	}

public:

	static void ShowManageUsersMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pCurrency))
		{
			return;
		}


		system("cls");
		_DrawScreenHeader("\t Currancy Exhange Main Screen");
		
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageCurrenciesMenueOption((enCurrencyScreenExhangeMenueOptions)ReadManageCurrenciesMenueOption());
	}
private:


};

