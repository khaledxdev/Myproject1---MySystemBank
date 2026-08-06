#pragma warning(disable : 4996)

#pragma once

#include<iostream>
#include<string>
using namespace std; 

class clsScreen
{

public:

	static void _DrawScreenHeader(string Title ,string SubTitle = "")
	{
		cout << "\t\t\t\t\t_____________________________________";
		cout << "\n\n\t\t\t\t\t " << Title << endl;

		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t " << SubTitle << endl;
		}


		cout << "\t\t\t\t\t_____________________________________\n\n";
	}

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            
            system("pause>0");
            return false;
        }
        else
        {
            return true;
        }

    }



};

