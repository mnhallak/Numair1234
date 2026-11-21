#pragma once
#include<iostream>
#include"clsScreen.h"

using namespace std;
class ShowCurrencyCalculatorScreen : protected clsScreen
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


public:

	static void ShowCurrencyCalculator()
	{
		char ch = 'N';
		string currencycode1;
		string currencycode2;
		float amount = 0;
		float result = 0;
		_DrawScreenHeader("Update Currency Screen");
		do
		{
			cout << "please eneter currency1 code" << endl;
			cin >> currencycode1;
			clsCurrency c1 = clsCurrency::FindCurrencybyCode(currencycode1);
			cout << "please eneter currency2 code" << endl;
			cin >> currencycode2;
			clsCurrency c2 = clsCurrency::FindCurrencybyCode(currencycode2);
			cout << "Enter amount to exchange" << endl;
			cin >> amount;
			cout << "convert from" << endl;
			_printCurrency(c1);
			cout << amount << " " << c1.GetCurrencyCode() << " = " << c1.ConvertCurrencytoAnotherCurrency(amount, c2) << " " << c2.GetCurrencyCode() << endl;
			cout << "Do you want to do another calculation? Y/N" << endl;
			cin >> ch;
		} while (toupper(ch)=='Y');
		
	}

};




