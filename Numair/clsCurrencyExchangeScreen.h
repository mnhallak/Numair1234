#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsShowListCurrencyScreen.h"
#include"clsShowFindCurrencyScreen.h"
#include"ShowUpdateCurrencyScreen.h"
#include"ShowCurrencyCalculatorScreen.h"

using namespace std;
class clsCurrencyExchangeScreen:protected clsScreen
{
private:

	enum enCurrency{eListCurrency=1, eFindCurrency=2, eUpdateRate=3, eCurrencyCalculator=4, eMainMenue=5};

	static int _ReadNumberOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		int choice=clsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;      
	}

	static void _GoBacktoMainManueCurrency()
	{
		system("cls");
		ShowCurrencyExchange();
	}

	static void _ShowListCurrency()
	{
		system("cls");
		clsShowListCurrencyScreen::ShowListCurrency();
		//cout<< setw(37) << left << "" << "List Currency Screen" << endl;
		system("pause");
		_GoBacktoMainManueCurrency();
	}

	static void _FindCurrency()
	{
		system("cls");
		clsShowFindCurrencyScreen::FindCurrency();
		//cout << setw(37) << left << "" << "Find Currency Screen" << endl;
		system("pause");
		_GoBacktoMainManueCurrency();
	}

	static void _UpdateRateCurrency()
	{
		system("cls");
		ShowUpdateCurrencyScreen::ShowUpdateCurrencyRate();
		//cout << setw(37) << left << "" << "Update Currency Screen" << endl;
		system("pause");
		_GoBacktoMainManueCurrency();
	}

	static void _ShowCurrencyCalculator()
	{
		system("cls");
		//cout << setw(37) << left << "" << " Currency Calculator Screen" << endl;
		ShowCurrencyCalculatorScreen::ShowCurrencyCalculator();
		system("pause");
		_GoBacktoMainManueCurrency();
	}

	static void _ShowMainManue()
	{
		system("cls");
		cout << setw(37) << left << "" << "Main Manue Screen" << endl;
		system("pause");
		//clsMainScreen::ShowMainMenue();
	}

	static void _PerformOption(enCurrency currency)
	{
		switch (currency)
		{
		case(enCurrency::eListCurrency):
		{
			_ShowListCurrency();
			break;
		}
		case(enCurrency::eFindCurrency):
		{
			_FindCurrency();
			break;
		}
		case(enCurrency::eUpdateRate):
		{
			_UpdateRateCurrency();
			break;
		}
		case(enCurrency::eCurrencyCalculator):
		{
			_ShowCurrencyCalculator();
			break;
		}
		case(enCurrency::eMainMenue):
		{
			_ShowMainManue();
			break;
		}
		}
	}


public:
	static void ShowCurrencyExchange()
	{
		_DrawScreenHeader("Currency Exchange Main Screen");
		cout << "\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t Currency Exchange Manue" << endl;
		cout << "\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t [1] List Currency" << endl;
		cout << "\t\t\t\t\t [2] Find Currency" << endl;
		cout << "\t\t\t\t\t [3] Update Rate" << endl;
		cout << "\t\t\t\t\t [4] Currency Calculator" << endl;
		cout << "\t\t\t\t\t [5] Main Manue" << endl;
		_PerformOption((enCurrency)_ReadNumberOption());
	}
};
