#pragma warning(disable : 4996)

#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInPutValidate.h"


class clsUpdateClientScreen : protected clsScreen  
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

	static void UpdateClient()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("Update Client Screen ");


		//Step1 
		cout << "Please Enter AccountNumber\n";
		string AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClintExist(AccountNumber)))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		//Step2 

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		Client1.Print();

		_ReadClientInfo(Client1);

		//Step3 

		clsBankClient::enSaveResult SvResult;
		SvResult = Client1.Save();


		switch (SvResult)
		{
		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			Client1.Print();
			break;
		}
		case clsBankClient::enSaveResult::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		}






	}


};

