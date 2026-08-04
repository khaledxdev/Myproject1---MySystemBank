#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInPutValidate.h"


class clsDeleteClientScreen : protected clsScreen
{


private:
	
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name: \n";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: \n";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: \n";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: \n";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter Pin Code: \n";
		Client.PinCod = clsInputValidate::ReadString();

		cout << "Enter Account Balance: \n";
		Client.AccountBalance = stof(clsInputValidate::ReadString());
	}

public:

	static void DeleteClient()
	{
		
		_DrawScreenHeader("Delete Client Screen");
		
		cout << "Please Enter AccountNumber\n";
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClintExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		Client1.Print();

		char obchan;
		cout << "\nAre you sure you want to delete this client y/n \n";
		cin >> obchan;


		if (obchan == 'y' || obchan == 'y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient Delete Successfully :-)\n";
				Client1.Print();
			}
			else
				cout << "\nError Client Was not Deleted\n";
		}

	}

};

