#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

using namespace std;
class clsAddUserScreen :protected clsScreen
{

private:
	static clsUser _ReadUserInfo(clsUser& user)
	{
		user.FirstName = clsInputValidate::ReadString("Please enter First Name: ");
		user.LastName = clsInputValidate::ReadString("Please enter Last Name: ");
		user.Email = clsInputValidate::ReadString("Please enter Email: ");
		user.Phone = clsInputValidate::ReadString("Please enter Phone: ");
		//user.UserName = clsInputValidate::ReadString("Please enter UserName: ");
		user.Password = clsInputValidate::ReadString("Please enter Password: ");
		user.Permissions = _GetPermissionsForUser();
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
	static int _GetPermissionsForUser()
	{
		cout << "\nDo you want give a permission to this user for all" << endl;
		int permission = 0;
		char ch = 'N';
		cin >> ch;
		if (toupper(ch) == 'Y')
		{
			return -1;
		}
		else if (toupper(ch) == 'N')
		{
			cout << "Do you want give a permission to this user for List Client" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enListClient;
			}
			cout << "Do you want give a permission to this user for Add Client" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enAddClient;
			}
			cout << "Do you want give a permission to this user for Delete Client" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enDeleteClient;
			}
			cout << "Do you want give a permission to this user for Update client" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enUpdateClient;
			}
			cout << "Do you want give a permission to this user for Find client" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enFindClient;
			}
			cout << "Do you want give a permission to this user for Transaction" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enTransaction;
			}
			cout << "Do you want give a permission to this user for manage users" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enManageUsers;
			}
			cout << "Do you want give a permission to this user for log in register User" << endl;
			cin >> ch;
			if (toupper(ch) == 'Y')
			{
				permission = permission + clsUser::enpermissions::enLogInRegister;
			}
		}
		return permission;
	}

public:

	static void ShowAddUser()
	{
		_DrawScreenHeader("Add New User Screen");
		string  username = "";
		username = clsInputValidate::ReadString("Please enter UserName: ");
		while (clsUser::IsUserExist(username))
		{
			cout << "UserName is found, please enter another UserName: " << endl;
			username = clsInputValidate::ReadString("Please enter UserName: ");
		}
		clsUser User =clsUser::GetAddNewUserObject(username);
		_ReadUserInfo(User);
		_PrintUser(User);
		clsUser::enSaveResults saveresult = User.Save();
		switch (saveresult)
		{
		case(clsUser::enSaveResults::svFaildUserExists):
		{
			cout << "\nuser is not added" << endl;
			break;
		}
		case(clsUser::enSaveResults::svSucceeded):
		{
			cout << "\nuser is added" << endl;
			break;
		}
			
		}
	}
};

