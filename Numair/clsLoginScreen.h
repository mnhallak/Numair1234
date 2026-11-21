#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsMainScreen.h"
#include"User.h"

using namespace std;
class clsLoginScreen:protected clsScreen
{

private:

	static bool _LogIn()
	{
		string username;
		string password;
		bool login = false;
		int count = 3;
		do
		{
			
			if (login)
			{
				cout << "Invalid username or password, please try again" << endl;
				count = count - 1;
				if (count == 0)
				{
					cout<< "You have exceeded the maximum number of login attempts" << endl;
					return 0;
				}
				cout << "You have (" << count << ") attempts left to log in" << endl;
			}
			cout << "please enter username" << endl;
			cin >> username;
			cout<< "please enter password" << endl;
			cin>> password;
			User=clsUser::Find(username, password);
			login = User.IsEmpty();
		} while (login);
		User.ShowSaveLogIn();
		clsMainScreen::ShowMainMenue();
	}


public:
	static bool ShowLogin()
	{
		_DrawScreenHeader("\t\t LogIn Screen");
		return _LogIn();
	}


};

