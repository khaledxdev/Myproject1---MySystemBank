#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include"clsInPutValidate.h"
#include"clsBankAccount.h"
using namespace std;

class clsDeposit
{

private:


	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Cart:";
		cout << "\n______________________________";
		cout << "\nFirstName   :" << Client.FirstName;
		cout << "\nLastName    :" << Client.LastName;
		cout << "\nFullName    :" << Client.FullName();
		cout << "\nEmail       :" << Client.Email;
		cout << "\nPhone       :" << Client.Phone;
		cout << "\nAcc. Number :" << Client.AccountNumber();
		cout << "\nPassword    :" << Client.PinCod;
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n______________________________\n";

	}
	
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:

	static void DepositScreen()
	{
	
		cout << "Please Enter AccountNumber\n";
		string AccountNumber = _ReadAccountNumber();

		while (!(clsBankClient::IsClintExist(AccountNumber)))
		{
			cout << "\nClient with ["<<AccountNumber<<"] does not exist";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "\nPlease Enter deposit amount? ";
		double Amount = clsInputValidate::ReadDblNumber();
		
		char Choice = 'n';
		cout << "\nAre you sure you want to preform this transaction? ";
		cin >> Choice;

		if (Choice == 'Y' || Choice == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is " << Client1.AccountBalance  << endl;
		}
		else
			cout<<"Operation was cancelled. " << endl;
	}




};

