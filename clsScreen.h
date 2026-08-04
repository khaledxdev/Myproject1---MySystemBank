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



};

