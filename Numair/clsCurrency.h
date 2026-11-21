#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"clsString.h"	
 
using namespace std;
class clsCurrency
{
private:

	enum enMode { Empety =0 , Update=1 };
	enMode _Mode;
	string _country;
	string _currencycode;
	string _currencyname;
	double _rate;

	static clsCurrency _ConvertCurrencyLinetoCurrencyObject(string line, string sep="#//#")
	{
		vector<string>vCurrency = clsString::Split(line, sep);
		return clsCurrency(enMode::Update, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}

	static clsCurrency _GetEmpetyCurrencyObject()
	{
		return clsCurrency(enMode::Empety, " ", " ", " ", 0);
	}



	

	string _ConvertCurrencyObjecttoCUrrencyLine(clsCurrency currency, string sep="#//#")
	{
		string currencyrecord = "";
		currencyrecord = currencyrecord + currency.GetCountry() + sep;
		currencyrecord = currencyrecord + currency.GetCurrencyCode() + sep;
		currencyrecord = currencyrecord + currency.GetCurrencyName() + sep;
		currencyrecord = currencyrecord + to_string(currency.GetRate()) + sep;
		return currencyrecord;
	}


	void _SaveCurrencyDatatoFile(vector<clsCurrency>vCurrency)
	{
		fstream myfile;
		string currencyline;
		myfile.open("Currency.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsCurrency C : vCurrency)
			{
				currencyline = _ConvertCurrencyObjecttoCUrrencyLine(C);
				myfile << currencyline << endl;
			}
			myfile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency>vCurrency = LoadCurrencyFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDatatoFile(vCurrency);
	}



public:

	clsCurrency(enMode mode , string country, string currencycode, string currencyname, double rate)
	{
		_Mode = mode;
		_country = country;
		_currencycode = currencycode;
		_currencyname = currencyname;
		_rate = rate;
	}

	string GetCountry()
	{
		return _country;

	}

	string GetCurrencyCode()
	{
		return _currencycode;

	}

	string GetCurrencyName()
	{
		return _currencyname;

	}

	void UpdateRate(double rate)
	{
		_rate = rate;
		_Update();
	}

	double GetRate()
	{
		return _rate;
	}

	
   
	static   clsCurrency FindCurrencybyCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currency.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLinetoCurrencyObject(Line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return  _GetEmpetyCurrencyObject();

	}

	static   clsCurrency FindCurrencybyName(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currency.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertCurrencyLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.GetCurrencyName()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmpetyCurrencyObject();

	}


	 bool IsEmpety()
	{
		return (_Mode == enMode::Empety);
	}

	static bool IsCurrencyExist(string  currencycode)
	{
		clsCurrency C = FindCurrencybyCode(currencycode);
			return (!C.IsEmpety());
	}

	static vector<clsCurrency> LoadCurrencyFromFile()
	{
		fstream myfile;
		string line;
		vector<clsCurrency>vCurrency;
		myfile.open("Currency.txt", ios::in);
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				clsCurrency currency = _ConvertCurrencyLinetoCurrencyObject(line);
				vCurrency.push_back(currency);
			}
			myfile.close();
		}
		return vCurrency;
	}
	
	float ConvertCurrencytoUsd(float amount)
	{
		return (amount / GetRate());
	}

	float ConvertCurrencytoAnotherCurrency(float amount, clsCurrency currency)
	{
		if (currency.GetCurrencyCode() == "USD")
		{
			return ConvertCurrencytoUsd(amount);
		}
		else
		{
			return (ConvertCurrencytoUsd(amount) * currency.GetRate());
		}
	}
};

