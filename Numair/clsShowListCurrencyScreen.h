#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std;
class clsShowListCurrencyScreen: protected clsScreen
{
private:

	static void _Print(clsCurrency currency)
	{
		cout << "|" << left << setw(30) << currency.GetCountry();
		cout << "|" << left << setw(10) << currency.GetCurrencyCode();
		cout << "|" << left << setw(35) << currency.GetCurrencyName();
		cout << "|" << left << setw(10) << currency.GetRate() << endl;
	}


public:

	static void ShowListCurrency()
	{
		vector<clsCurrency>vCurrency = clsCurrency::LoadCurrencyFromFile();
		string Title = "Currency List Screen";
		string SubTitle = to_string(vCurrency.size()) + "  Currencies";
		_DrawScreenHeader(Title, SubTitle);
		cout << "______________________________________________________________________________________" << endl;
		cout << "|" << left << setw(30) << "Country";
		cout << "|" << left << setw(10) << "Code";
		cout << "|" << left << setw(35) << "Name";
		cout << "|" << left << setw(10) << "Rate (/1$)"<<endl;
		cout << "______________________________________________________________________________________" << endl;
		for (clsCurrency C1 : vCurrency)
		{
			_Print(C1);
		}
	}


};

