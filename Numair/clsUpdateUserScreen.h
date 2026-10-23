#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;

class clsUpdateUserScreen: protected clsScreen
{
private:

	static clsUser _ReadUserInfo(clsUser user)
	{
		user.FirstName = clsInputValidate::ReadString("Please enter First Name: ");
		user.LastName = clsInputValidate::ReadString("Please enter Last Name: ");
		user.Email = clsInputValidate::ReadString("Please enter Email: ");
		user.Phone = clsInputValidate::ReadString("Please enter Phone: ");
		user.UserName = clsInputValidate::ReadString("Please enter UserName: ");
		user.Password = clsInputValidate::ReadString("Please enter Password: ");
		user.Permissions = clsInputValidate::ReadIntNumber("Please enter Permissions: ");
		return user;
	}

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

	static void ShowUpdateUser()
	{
		clsScreen::_DrawScreenHeader("Update User Screen");
		string  username = "";
		username=clsInputValidate::ReadString("Please enter UserName: ");
		while (!clsUser::IsUserExist(username))
		{
			cout << "UserName is not found, please enter another UserName: " << endl;
			username = clsInputValidate::ReadString("Please enter UserName: ");
		}
        clsUser User = clsUser::Find(username);
        _PrintUser(User);
		cout << "\nAre you sure you want to update this user y/n? ";
		char ch = 'N';
		cin >> ch;
		if (toupper(ch == 'Y'))
		{
			_ReadUserInfo(User);
			User.Save();
			cout << "\nUser Updated Successfully :-)\n";
		}
		else
		{
			cout << "\nUpdate Canceled :-)\n";
		}
	}
};

