#pragma once
#include <iostream>
#include"User.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle ="")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\t User: "<< User.UserName << endl;
        cout << "\n\t\t\t\t\t Date: "<< clsDate::DateToString(clsDate()) << endl;
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }
   
    static bool CheckAccessRights(clsUser::enpermissions permission)
    {
        if (!User.CheckAccessPermission(permission))
        {
            cout << "\t\t\t============================================================" << endl;
            cout << "\t\t\tAccess denied, Please contact your administrator" << endl;
            cout << "\t\t\t============================================================" << endl;
            return false;
        }
        else
        {
            return true;
        }
    }
};



