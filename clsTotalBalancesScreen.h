#pragma warning(disable : 4996)
#pragma once


#include"clsBankClient.h"
#include"clsUtil.h"


class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << setw(30) << left << "";
        cout << "| " << left << setw(15) << Client.FullName();
       
        cout << "| " << left << setw(25) << Client.AccountNumber();
        cout << "| " << left << setw(10) << Client.AccountBalance;
    }

public:

    static void ShowTotalBalances()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientList();

        // Step 1
        string Title = "\tBalances List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";
        clsScreen::_DrawScreenHeader(Title, SubTitle);



        cout << setw(24) << left << "" << "_______________________________________________";
        cout << "________________________\n\n";

        cout << setw(30) << left << "";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(25) << "Client Name";
        cout << "| " << left << setw(10) << "Balance";

        cout << setw(25) << left << "" << "\n\t\t\t_______________________________________________";
        cout << "________________________\n\n";

        double TotalBalances = clsBankClient::GetTotalBalances();


        for (clsBankClient C : vClients)
        {
            _PrintClient(C);  
            cout << endl;
        }
        

        cout << "\n\n\t\t\t\t\t Total Balances = " << TotalBalances << endl;
        cout << "\n\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")" ;



	}


};

