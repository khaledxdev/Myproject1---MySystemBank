#pragma warning(disable : 4996)

#pragma once

#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsPerson.h"
#include"clsInPutValidate.h"

class clsFindClientScreen : protected clsScreen
{

public:

	static void Find()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("Find Client Screen ");
		
		cout << "Please Enter AccountNumber\n";
		string AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClintExist(AccountNumber)))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		//Step2 

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		
		if (!Client1.IsEmpty())
			cout << "Client Found\n";
		else
			cout << "Client was not Found\n";
								
		
		Client1.Print();
	}
};

