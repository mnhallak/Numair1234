#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsDate.h"
#include"clsUser.h"
#include"clsBankClient.h"

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;



    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

  

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    string _ConvertTransferDatatoLine(double amount, clsBankClient toClient, string sep = "#//#")
    {
        string transferdataline = "";
        transferdataline = transferdataline + clsDate::DateToString(clsDate()) + sep;
        transferdataline = transferdataline + AccountNumber() + sep;
        transferdataline = transferdataline + toClient.AccountNumber() + sep;
        transferdataline = transferdataline + to_string(amount) + sep;
        transferdataline = transferdataline + to_string(AccountBalance) + sep;
        transferdataline = transferdataline + to_string(toClient.AccountBalance) + sep;
        transferdataline = transferdataline + User.UserName + sep;
        return transferdataline;
    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

     void Deposit(double amount)
    {
        AccountBalance = AccountBalance + amount;
        Save();
    }

     void Withdraw(double amount)
    {
        AccountBalance = AccountBalance - amount;
        Save();
    }

     static double GetTotalBalances()
     {
         double sum = 0;
         vector<clsBankClient> vClient = _LoadClientsDataFromFile();
         for (clsBankClient C: vClient)
         {
             sum = sum + C.AccountBalance;
         }
         return sum;
     }

     bool Transfer(double amount, clsBankClient & toClient)
     {

         if (amount > AccountBalance)
         {
             return false;
         }
         else
         {
             Withdraw(amount);
             toClient.Deposit (amount);
             SaveTransferDatatoFile(amount, toClient);
             return true;
         }
     }

    

     void SaveTransferDatatoFile(double amount, clsBankClient toClient)
     {
         fstream myfile;
         string transferdataline = _ConvertTransferDatatoLine(amount, toClient);
         myfile.open("TransferLogFile.txt", ios::out | ios::app);
         if (myfile.is_open())
         {
             myfile << transferdataline << endl;
             myfile.close();
         }
     }


     struct stTransferDataLog {
         string TransferDate; string sourceaccountnumber; string destinationaccountnumber; double amount; double sourcebalance;
         double destinationbalance; string User;
     };


     static stTransferDataLog ConvertTransferLogtoRecord(string line, string sep = "#//#")
     {
         stTransferDataLog TransferDataLog;
         vector<string> vTransferLogs = clsString::Split(line, sep);
         TransferDataLog.TransferDate = vTransferLogs[0];
         TransferDataLog.sourceaccountnumber = vTransferLogs[1];
         TransferDataLog.destinationaccountnumber = vTransferLogs[2];
         TransferDataLog.amount = stod(vTransferLogs[3]);
         TransferDataLog.sourcebalance = stod(vTransferLogs[4]);
         TransferDataLog.destinationbalance = stod(vTransferLogs[5]);
         TransferDataLog.User = vTransferLogs[6];
         return TransferDataLog;
     }
    

     static vector<stTransferDataLog> LoadTransferLogsFromFile()
     {
         fstream myfile;
         stTransferDataLog TransferDataLog;
         string line;
         vector<stTransferDataLog> vTransferLogs;
         myfile.open("TransferLogFile.txt", ios::in);
         if (myfile.is_open())
         {
             while (getline(myfile, line))
             {
                 TransferDataLog = ConvertTransferLogtoRecord(line);
                 vTransferLogs.push_back(TransferDataLog);
             }
             myfile.close();
             return vTransferLogs;
         }
     }

};


