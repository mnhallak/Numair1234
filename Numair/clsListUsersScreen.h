#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsListUsersScreen:protected clsScreen
{

private:

	static void _PrintListUsers()
	{
		vector<clsUser>users = clsUser::GetUsersList();
		for (clsUser U : users)
		{
			cout << "|" << left << setw(15) << U.UserName;
			cout << "|" << left << setw(30) << U.FullName();
			cout << "|" << left << setw(15) << U.Phone;
			cout << "|" << left << setw(30) << U.Email;
			cout << "|" << left << setw(15) << U.Password;
			cout << "|" << left << setw(15) << U.Permissions;
			cout << endl;
		}
		cout << "______________________________________________________________________________________________________________________________________" << endl;
	}
public:
	static void ShowListUsers()
	{
		vector<clsUser>users=clsUser::GetUsersList();
		string title = "User List Screen";
		string subtitle = "(" + to_string(users.size()) + ")" + "users";
		clsScreen::_DrawScreenHeader(title, subtitle);
		cout << "______________________________________________________________________________________________________________________________________" << endl;
		cout << "|" << left << setw(15) << "user name";
		cout << "|" << left << setw(30) << "Full name";
		cout << "|" << left << setw(15) << "Phone";
		cout << "|" << left << setw(30) << "Email";
		cout << "|" << left << setw(15) << "Password";
		cout << "|" << left << setw(15) << "permissions";
		cout << endl;
		cout << "______________________________________________________________________________________________________________________________________" << endl;
		_PrintListUsers();
	}
};

