#pragma once

#include"clsGlobal.h"
#include"clsScreen.h"
#include"clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{

private:

	static void _Login()
	{
		bool LoginFail = false;
		string UserName, Password;

		do 
		{

			if (LoginFail)
			{
				cout << "\nInvalid Username/Password!\n";
			}


			cout << "\nEnter Username? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);

			LoginFail = CurrentUser.IsEmpty();

		} while (LoginFail);
		
		clsMainScreen::ShowMainMenu();
	}



public:

	static void ShowLoginScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t    Login Screen");
		_Login();
	}





};

