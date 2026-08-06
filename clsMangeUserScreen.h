#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInPutValidate.h"
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUser.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"iomanip"
using namespace std;


class clsMangeUserScreen : protected clsScreen
{

private:

	enum enMainMenueManageUser {

		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5,  eBackeToMainManu = 6,
		

	};


	static short _ReadManageUsersMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\nPress any key to go back to Manage Users Menu...";
		system("pause>0");
		ShowManageUser();
	}

	static void _ShowListUserScreen()
	{
		clsListUserScreen::ShoeUserList();
	}
	
	static void _ShowAddNewClientScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUser::showDeleteUserScreen();
	}

	static void _ShowUpdateScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::showFindUserScreen();
	}


	static void _PerformMangeUserMenuOption(enMainMenueManageUser ManageUser)
	{

		switch (ManageUser)
		{
		case enMainMenueManageUser::eListUser:
		{ 
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enMainMenueManageUser::eAddNewUser:
		{
			 system("cls");
			_ShowAddNewClientScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enMainMenueManageUser::eDeleteUser:
		{
			 system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enMainMenueManageUser::eUpdateUser:
		{
			 system("cls");
			_ShowUpdateScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enMainMenueManageUser::eFindUser:
		{
			 system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;
		}
		case enMainMenueManageUser::eBackeToMainManu:
		{
		

		}
		}
	}


public:

	static void ShowManageUser()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}


		system("cls");
		clsScreen::_DrawScreenHeader("\t Manage User Screen ");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMangeUserMenuOption((enMainMenueManageUser)_ReadManageUsersMenuOption());

	}
	

	





};

