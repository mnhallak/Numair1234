#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;
class clsTransferScreen:protected clsScreen
{
private:


	static void _PrintClientCard(clsBankClient client)
	{
		cout << "\n Client Card" << endl;
		cout << "==========================" << endl;
		cout<<"Full Name: "<<client.FullName()<<endl;
		cout<<"Account Number: "<<client.AccountNumber()<<endl;
		cout<<"Balance: "<<client.AccountBalance<<endl;
		cout << "==========================" << endl;
	}


public:

	static void ShowTransfer()
	{
		double amount = 0;
		string accountnumber = "";
		string toAccountNumber = "";
		_DrawScreenHeader("Transfer Screen");
		cout << "Please enter the account number to transfer from :" << endl;
		accountnumber = clsInputValidate::ReadString(accountnumber);
		clsBankClient client1 = clsBankClient::Find(accountnumber);
		while (!clsBankClient::IsClientExist(accountnumber))
		{
			cout << "Account number does not exist, please enter a valid account number: " << endl;
			accountnumber = clsInputValidate::ReadString(accountnumber);
		}
		_PrintClientCard(client1);
		cout << "Please enter the account number to transfer to :" << endl;
		toAccountNumber = clsInputValidate::ReadString(toAccountNumber);
		clsBankClient client2 = clsBankClient::Find(toAccountNumber);
		while (!clsBankClient::IsClientExist(toAccountNumber))
		{
			cout << "Account number does not exist, please enter a valid account number: " << endl;
			toAccountNumber = clsInputValidate::ReadString(toAccountNumber);
		}
		_PrintClientCard(client2);
		cout << "Enter transfer amount: " << endl;
		cin >> amount;
		cout << "Are you sure you want to transfer(Y/N)?" << endl;
		char ch = 'N';
		cin >> ch;
		if (toupper(ch) == 'Y')
		{
			if (client1.Transfer(amount, client2))
			{
				cout << "Transfer successful." << endl;
			}
			else
			{
				cout << "Transfer failed due to insufficient balance." << endl;
			}
		_PrintClientCard(client1);
		_PrintClientCard(client2);
	    }
	}
};

