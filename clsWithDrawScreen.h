#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include"clsInPutValidate.h"
#include"clsBankClient.h"
#include"clsWithDrawScreen.h"
using namespace std;

class clsWithDrawScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCod;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

	static void ShowWithDrawScreen()
	{
        clsScreen::_DrawScreenHeader("WithDraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClintExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();

        int Amount = 0;
        cout << "Please Enter WithDraw amount\n";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insufficient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client.AccountBalance;
            }

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
      
	}

};

