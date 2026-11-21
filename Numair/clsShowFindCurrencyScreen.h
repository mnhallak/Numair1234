#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include<string>
#include"clsInputValidate.h"

using namespace std;
class clsShowFindCurrencyScreen: protected clsScreen
{
private:

	static void _printCurrency(clsCurrency currency)
	{
		cout << " Currency Card" << endl;
		cout << "___________________________" << endl;
		cout << "Country : " << currency.GetCountry()<<endl;
		cout << "Code : " << currency.GetCurrencyCode()<<endl;
		cout << "Name : " << currency.GetCurrencyName()<<endl;
		cout << "Rate/(1$) : " << currency.GetRate()<<endl;
		cout << "___________________________" << endl;
	}

public:

	static void FindCurrency()
	{
		_DrawScreenHeader("Find Currency Screen");
		cout << "Find by [1] code or [2] country ?" << endl;
		short num = 1;
		cin >> num;
		if (num == 1)
		{
			cout << "please eneter country code" << endl;
			string currenycode;
			cin >> currenycode;
			clsCurrency c1 = clsCurrency::FindCurrencybyCode(currenycode);
			_printCurrency(c1);
		}
		else 
		{
			cout << "please eneter country name" << endl;
			string currencyname;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, currencyname);
			clsCurrency c2 = clsCurrency::FindCurrencybyName(currencyname);
			_printCurrency(c2);
		}
	}
};

