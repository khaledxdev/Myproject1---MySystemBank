#pragma warning(disable : 4996)

#pragma once

#include<iostream>
#include<string>
using namespace std;


class clsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}

	void setFirsName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = setFirsName)) string FirstName;

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = setLastName)) string LastName;

	void setEmil(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = setEmil)) string Email;

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = setPhone)) string Phone;


	string FullName()
	{
		return FirstName + " " + LastName;
	}

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n_______________________________";
		cout << "\nFirstName : " << _FirstName;
		cout << "\nLastName  : " << _LastName;
		cout << "\nFullName  : " << FullName();
		cout << "\nEmail     : " << _Email;
		cout << "\nPhone     : " << _Phone;
		cout << "\n_______________________________\n";
	}



};

