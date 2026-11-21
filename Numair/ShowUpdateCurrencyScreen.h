#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std;
class ShowUpdateCurrencyScreen: protected clsScreen
{
private:
	static void _printCurrency(clsCurrency currency)
	{
		cout << " Currency Card" << endl;
		cout << "___________________________" << endl;
		cout << "Country : " << currency.GetCountry() << endl;
		cout << "Code : " << currency.GetCurrencyCode() << endl;
		cout << "Name : " << currency.GetCurrencyName() << endl;
		cout << "Rate/(1$) : " << currency.GetRate() << endl;
		cout << "___________________________" << endl;
	}

	static float _ReadNewRate()
	{
		float newrate = 0;
		cout << "Enter new rate" << endl;
		cin >> newrate;
		return newrate;
	}


public:
	static void ShowUpdateCurrencyRate()
	{
		_DrawScreenHeader(" Update Currency Screen");
		cout << "Please Enter Currency code : ";
		string currencycode;
		cin >> currencycode;
		clsCurrency C1= clsCurrency::FindCurrencybyCode(currencycode);
		_printCurrency(C1);
		cout << "Are you sure you want to update the rate of this currenty? Y/N" << endl;
		char ch = 'N';
		cin >> ch;
		if (toupper(ch) == 'Y')
		{
			cout << "Update currenty rate" << endl;
			cout << "_______________________________" << endl;
			C1.UpdateRate(_ReadNewRate());
			cout << "Currency Rate is updated successfully " << endl;
			_printCurrency(C1);
		}
	}
};

