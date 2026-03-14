#pragma once
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsString.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{

    static void _PrintCurrency(clsCurrency Currency,string Mag)
    {
        cout << Mag;
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    } 


    static void _PrintResultsToDollar(clsCurrency Currency,float Amount)
    {
        cout << Amount << "  " << Currency.CurrencyCode() << " = " << Currency.ConvertFromCurrencyToDollar(Amount) << "  USD \n ";
    }

    static void _PrintResultsFromDollar(clsCurrency SCurrency,clsCurrency DCurrency, float Amount)
    {
        cout << Amount << "  " << SCurrency.CurrencyCode() << " = " << DCurrency.ConvertFromDollarToCurrency(Amount) << " " << DCurrency.CurrencyCode() << " \n ";
    }

public:
	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("\t Currency Calculator Screen");
		string Code1, Code2;
        float Amount;
		cout << "Please Enter Currency1 Code:\n";
		Code1 = clsInputValidate<string>::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code1))
        {
            cout << "\nCurrency is not found, choose another one: ";
            Code1 = clsInputValidate<string>::ReadString();
        }
        cout << "Please Enter Currency2 Code:\n";
        Code2 = clsInputValidate<string>::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code2))
        {
            cout << "\nCurrency is not found, choose another one: ";
            Code2 = clsInputValidate<string>::ReadString();
        }
        cout << "\nEnter Amount to Exchange: ";
        cin >> Amount;
		clsCurrency Source = clsCurrency::FindByCode(Code1);
        clsCurrency Destination = clsCurrency::FindByCode(Code2);
        _PrintCurrency(Source,"\nCurrency From:\n");
        _PrintResultsToDollar(Source, Amount);
        if (clsString::UpperAllString(Destination.CurrencyCode())!="USD")
        {
            _PrintCurrency(Destination, "\n To:\n");
            _PrintResultsFromDollar(Source, Destination, Amount);
        }
	}
};

