#pragma once

#include<vector>
#include"clsUser.h"

class clsListUserScreen : protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "|" << setw(14) << left << User.UserName;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(22) << User.Email;
		cout << "| " << left << setw(12) << User.Password;
		cout << "| " << left << setw(10) << User.Permissions;
	}




public:



	static void ShoeUserList()
	{
		vector<clsUser> vUser = clsUser::GetUsersList();
		string  SizeUser = to_string (vUser.size());


		string Title = "\tUser List Screen";
		string SubTitle = "\t   " + SizeUser + " User(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_____________________________________________________________";
		cout << "________________________________________________\n\n";

		cout << setw(8) << left << "" << "|" << "User Name" << setw(5) << left << "";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(22) << "Email";
		cout << "| " << left << setw(12) << "PassWord";
		cout << "| " << left << setw(10) << "Permissions|";

		cout << "\n\t_____________________________________________________________";
		cout << "________________________________________________\n\n";


		if (SizeUser.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available In the System!";
		}
		else
		{
			for (clsUser& C : vUser)
			{
				_PrintUserRecordLine(C);
				cout << endl;
			}

		}

		cout << "\n\t_____________________________________________________________";
		cout << "________________________________________________\n\n";


	}


};

