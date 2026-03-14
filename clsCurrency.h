#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
class clsCurrency
{
	enum enMode {
		EmptyMode = 0, UpdateMode = 1
	};
	enMode Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], stof(vUserData[3]));

	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += Currency._Country + Seperator;
		UserRecord += Currency._CurrencyCode + Seperator;
		UserRecord += Currency._CurrencyName + Seperator;
		UserRecord += to_string(Currency._Rate);

		return UserRecord;

	}

	static  vector <clsCurrency> _LoadCurrencyDataFromFile()
	{

		vector <clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode 

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currnecy = _ConvertLinetoCurrencyObject(Line);

				vCurrency.push_back(Currnecy);
			}

			MyFile.close();

		}

		return vCurrency;

	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrency)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency U : vCurrency)
			{
					DataLine = _ConverCurrencyObjectToLine(U);
					MyFile << DataLine << endl;


			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencyDataFromFile();

		for (clsCurrency& U : _vCurrencys)
		{
			if (U.CurrencyCode() == U.CurrencyCode())
			{
				U = *this;
				break;
			}

		}

		_SaveCurrenciesDataToFile(_vCurrencys);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		this->Mode = Mode;
		this->_Country = Country;
		this->_CurrencyCode = CurrencyCode;
		this->_CurrencyName = CurrencyName;
		this->_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string code)
	{
		code = clsString::UpperAllString(code);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == code)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}


	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string code)
	{

		clsCurrency Currency = clsCurrency::FindByCode(code);
		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurreciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertFromCurrencyToDollar(float Amont)
	{
		return Amont / Rate();
	}

	float ConvertFromDollarToCurrency(float Amont)
	{
		return Amont * Rate();
	}
};