#pragma once

#include"clsScreen.h"
#include "clsUser.h"
#include"clsInPutValidate.h"
class clsFindUserScreen : protected clsScreen
{


private:

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

	static void showFindUserScreen()
	{
		clsScreen::_DrawScreenHeader("\tFind User Screen ");

		cout << "\nPlease Enter User Name: ";
		string UserName =  clsInputValidate::ReadString();
		
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one: ";
			UserName =  clsInputValidate::ReadString();

		}
		
		clsUser User1 = clsUser::Find(UserName);

		if (!(User1.IsEmpty()))
		{
			cout << "\nUser Found :-)";
			_PrintUser(User1);
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}

	}


};

