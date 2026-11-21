#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;
class clsShowTransferLogScreen : protected clsScreen
{
private:

	static void _Print(clsBankClient::stTransferDataLog TransferDataLog)
	{
		cout << "|" << left << setw(12) <<  TransferDataLog.TransferDate;
		cout << "|" << left << setw(8)<< TransferDataLog.sourceaccountnumber;
		cout << "|" << left << setw(8) << TransferDataLog.destinationaccountnumber;
		cout << "|" << left << setw(8) << TransferDataLog.amount;
		cout << "|" << left << setw(8) << TransferDataLog.sourcebalance;
		cout << "|" << left << setw(8) << TransferDataLog.destinationbalance;
		cout << "|" << left << setw(8) << TransferDataLog .User<< endl;
	}


public:
	static void ShowTransferLog()
	{
		vector<clsBankClient::stTransferDataLog>vTransferDataLog = clsBankClient::LoadTransferLogsFromFile( );
		string Title="Transfer Log ListScreen";
		string SubTitle = to_string(vTransferDataLog.size())+" "+ "Records";
		_DrawScreenHeader(Title, SubTitle);
		cout << "======================================================================================================================" << endl;
		cout << "|" << left << setw(12) <<  "Date/Time";
		cout << "|" << left << setw(8) << "s Acc";
		cout << "|" << left << setw(8) << "Dis Acc";
		cout << "|" << left << setw(8) << "Amount";
		cout << "|" << left << setw(8) << "s Bal";
		cout << "|" << left << setw(8) << "Dis Bal";
		cout << "|" << left << setw(8) << "User" << endl;
		cout << "======================================================================================================================" << endl;
		for(clsBankClient::stTransferDataLog U: vTransferDataLog)
		{ 
			_Print(U);
		
		}
	}
	
};

