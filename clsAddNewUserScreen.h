#pragma once

#include"clsScreen.h"
#include"clsUser.h" 
#include"clsInPutValidate.h"


class clsAddNewUserScreen : protected clsScreen 
{

private:


	static int _ReadPermission()
	{
		int Permission = 0;
		char Answer = 'n';



		cout << "\nDo you want to give full access? y/n>? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			return -1;
		}
		
		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTreactions y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pTranactions;
		}

		cout << "\ManageUser y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pManageUsers;
		}

		return Permission;
	}


	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PassWord: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermission();


	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}


public:

	static void ShowAddNewUserScreen()
	{
		clsScreen::_DrawScreenHeader("\tAdd New User Screen");

		// 1
		string UsarName = "";
		cout << "\nPlease Enter User Name: ";
		UsarName = clsInputValidate::ReadString();

		// 2
		while (clsUser::IsUserExist(UsarName))
		{
			cout << "\n is not found, choose another one: ";
			UsarName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UsarName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults svResult;

		svResult = NewUser.Save();

		switch (svResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because it's Empty";
			break;
		}
		case clsUser::svFaildUserExists:
		{
			cout << "\nError User was not saved because UserName is used!\n";
			break;
		}
		}

	}

};

