#pragma warning(disable : 4996)

#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInPutValidate.h"

class clsAddNewClientScreen : public clsScreen
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

	 static void AddClient()
	 {


		 if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		 {
			 return;// this will exit the function and it will not continue
		 }

		//Step1 

		cout << "Please Enter AccountNumber\n";
		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClintExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		//Step2 

		clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

		_ReadClientInfo(NewClient);

		//Step3 

		clsBankClient::enSaveResult SvResult;
		SvResult = NewClient.Save();



		switch (SvResult)
		{
		case clsBankClient::enSaveResult::svSucceeded: // ?? ???? ?????? 
		{
			cout << "\nAccount Added Successfully :-)\n";
			NewClient.Print();
			break;

		}
		case clsBankClient::enSaveResult::svFaildEmptyObject: // ?? ???? ??? ???? 
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsBankClient::enSaveResult::svFaildAccountNumberExists: // ?? ???? ?? ??? ?????? ????? ?????? 
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}

		}

	}

};

