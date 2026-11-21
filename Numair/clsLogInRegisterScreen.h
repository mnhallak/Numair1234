#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsString.h"

using namespace std;
class clsLogInRegisterScreen:protected clsScreen
{
private:

	static void _PrintLogInRecordInfo(clsUser::stLoginRecord record)
	{
		cout << "|" << left << setw(30) << record.date;
		cout << "|" << left << setw(30) << record.username;
		cout << "|" << left << setw(30) << record.password;
		cout << "|" << left << setw(15) << record.permission << endl;
	}

public:
	static void ShowLogInList()
	{
		if (!CheckAccessRights(clsUser::enpermissions::enLogInRegister))
		{
			return;
		}

		string title = "Log in Register List Screen";
		string subtitle = to_string(clsUser::GetLogInRegisterLine().size()) + "  Record(s).";
		_DrawScreenHeader(title, subtitle);
		cout << "=============================================================================" << endl;
		cout << "|" << left << setw(30) << "Date";
		cout << "|" << left << setw(30) << "UserName";
		cout << "|" << left << setw(30) << "Password";
		cout << "|" << left << setw(15) << "Permission" << endl;
		cout << "=============================================================================" << endl;

		for (clsUser::stLoginRecord record : clsUser::GetLogInRegisterLine())
		{
			_PrintLogInRecordInfo(record);
		}
	}
};

