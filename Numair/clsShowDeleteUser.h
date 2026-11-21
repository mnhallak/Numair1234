#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsShowDeleteUser : protected clsScreen
{

private:

	static void _PrintUser(clsUser user)
	{
		cout<< "\nUser Card:\n";
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

	static void ShowDeleteUsers()
	{
		clsScreen::_DrawScreenHeader("Delete User Screen");
		string username = "";
		username=clsInputValidate::ReadString("Enter username to delete:");
		while(!clsUser::IsUserExist(username))
		{
			cout << "User not found. Please try again." << endl;
			username = clsInputValidate::ReadString("Enter username to delete:");
		}
		clsUser user = clsUser::Find(username);
		_PrintUser(user);

		cout << "\nAre you sure want to delete this user?(Y/N)" << endl;
		char ch = 'N';
		cin >> ch;
		if (toupper(ch) == 'Y')
		{
			if (user.Delete())
			{
				_PrintUser(user);
				cout << "\nUser is deleted successfully." << endl;
			}
		}
		else
		{
			cout << "User is not deleted" << endl;
		}
			
	}
};

