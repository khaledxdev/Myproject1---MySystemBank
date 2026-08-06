#pragma warning(disable : 4996)

#pragma once

#include"clsScreen.h"
#include"clsBankClient.h"

class clsClientListScreen : protected clsScreen
{
private:
	

	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout<<setw(8) << left<<"\t|"<<setw(9)<<left << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCod;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("List Clients Screen");

		vector<clsBankClient>vClients = clsBankClient::GetClientList();

		string Title = "\t Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		
		cout << setw(8) << left << "" << "|" << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vClients.size() == 0)

			cout << "No Client Available In the System!\n";
		else
			for (clsBankClient C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;





	}




};

