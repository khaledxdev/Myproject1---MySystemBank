#pragma warning(disable : 4996)

#pragma once

#include <iostream>
#include "clsScreen.h"
#include <string>
#include "clsInPutValidate.h"
#include"clsBankClient.h"
#include <iomanip>
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransaction.h"
#include"clsMangeUserScreen.h"
#include"clsGlobal.h"

using namespace std;


class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenueOptions {

		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindCleint = 5, eShwoTrasationMenue = 6,
		eManageUsers = 7, eExit = 8

	};

	static int _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		int Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 8");	
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "\nPlease any Key to go back to Main Menu...\n";
		
		system("pause>0");
		ShowMainMenu();
	}

	
	static void _ShowAllClientScreen()
	{
		clsClientListScreen::ShowClientsList();
	}
	static void _ShowAddMNewClientScreen()
	{
		clsAddNewClientScreen::AddClient();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}
	static void _ShowFindNewClientScreen()
	{
		clsFindClientScreen::Find();
	}
	static void _ShowTransactionMenu()
	{
		clsTransaction::ShowTransactionMenu();
	}
	static void _ShowManageUsersMenu()
	{
		clsMangeUserScreen::ShowManageUser();
	}

	 
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}


	static void _PerformMainMenuOption(enMainMenueOptions ManeMenuOption)
	{
		switch (ManeMenuOption)
		{
		case enMainMenueOptions::eListClient:
		{
			system("cls");
			_ShowAllClientScreen();
			_GoBackToMainMenu();
			break;

		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddMNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eFindCleint:
		{
			system("cls");
			_ShowFindNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenueOptions::eShwoTrasationMenue:
		{
			system("cls");
			_ShowTransactionMenu();
			break;

		}
		case enMainMenueOptions:: eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenu();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}

		}


	}
	
public: 

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Screen\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client.\n";
		cout << setw(37) << left << "" << "\t[5] Fine Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Mange Users.\n";
		cout << setw(37) << left << "" << "\t[8] LogOut.\n";
		cout << setw(37) << left << "" << "=============================================\n";
		


		_PerformMainMenuOption((enMainMenueOptions) _ReadMainMenuOption());
	}


};

