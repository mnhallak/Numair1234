#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;
class clsFindUserScreen:protected clsScreen
{
private:


	static void _PrintUser(clsUser user)
	{
		cout << "\nUser Card:\n";
		cout << "__________________________\n";
		cout << "\nFirstName: " << user.FirstName;
		cout << "\nLastName: " << user.LastName;
		cout << "\nEmail: " << user.Email;
		cout << "\nPhone: " << user.Phone;
		cout << "\nUserName: " << user.UserName;
		cout << "\nPassword: " << user.Password;
		cout << "\nPermissions: " << user.Permissions;
	}

public:

	static void ShowFindUser()
	{

		clsScreen::_DrawScreenHeader("Find User Screen");
		string  username = "";
		username = clsInputValidate::ReadString("Please enter UserName: ");
		while (!clsUser::IsUserExist(username))
		{
			cout << "UserName is not found, please enter another UserName: " << endl;
			username = clsInputValidate::ReadString("Please enter UserName: ");
		}

		clsUser user=clsUser::Find(username);
		_PrintUser(user);
	}
};

