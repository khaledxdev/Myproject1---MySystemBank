#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInPutValidate.h"
#include"clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalancesScreen.h"

using namespace std;


class clsTransaction : protected clsScreen
{
private: 
	 
	enum enMainMenuOptional
	{
		Deposit = 1,
		Withdraw = 2,
		TotalBalance = 3,
		MainMenu = 4
	};


	static int _ReadMainMenuScreen()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 4] ?";
		int choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter your Between 1 to 4");
		
		return choice;
	}
	static void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "\nPlease any Key to go back to Main Menu...\n";
		system("pause>0");
		ShowTransactionMenu();
	}

	static void _PerformMainMenuOption (enMainMenuOptional MainMenuOptional)
	{
		switch (MainMenuOptional)
		{
		case enMainMenuOptional::Deposit:
		{
			system("cls");
			clsDepositScreen::ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enMainMenuOptional::Withdraw:
		{
			system("cls");
			clsWithDrawScreen::ShowWithDrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enMainMenuOptional::TotalBalance:
		{
			system("cls");
			clsTotalBalancesScreen::ShowTotalBalances();
			_GoBackToTransactionsMenu();
			break;
		}
		case enMainMenuOptional::MainMenu:
		{
		}

		}
	
	}



public:

	static void  ShowTransactionMenu()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;// this will exit the function and it will not continue
		}


		system("cls");
		_DrawScreenHeader("\tTransaction Screen");

		cout << setw(37) << left << "" << "\t===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menu \n";
		cout << setw(37) << left << "" << "\t===========================================\n";
		cout << setw(43) << left << "" << "[1] Deposit.\n";
		cout << setw(43) << left << "" << "[2] Withdraw.\n";
		cout << setw(43) << left << "" << "[3] TotalBalances.\n";
		cout << setw(43) << left << "" << "[4] Main Menu.\n";

		_PerformMainMenuOption((enMainMenuOptional)_ReadMainMenuScreen());

	
	}

};

