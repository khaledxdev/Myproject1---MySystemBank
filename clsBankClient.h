#pragma warning(disable : 4996)

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"clsPerson.h"
#include<vector>
#include"clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };

	enMode _Mode;

	string _AccountNumber;
	string _PinCod;
	double  _AccountBalance;
	bool _MarkedForDelete = false;


	static clsBankClient _ConvertLineToClintObject(string Line, string Delime = "#//#")
	{
		vector<string>vClint;
		vClint = clsString::Split(Line, Delime);

		return clsBankClient(enMode::UpdateMode,
			vClint[0], vClint[1], vClint[2], vClint[3],
			vClint[4], vClint[5], stof(vClint[6]));

	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Separator;
		stClientRecord += Client.LastName + Separator;
		stClientRecord += Client.Email + Separator;
		stClientRecord += Client.Phone + Separator;
		stClientRecord += Client.AccountNumber() + Separator;
		stClientRecord += Client.PinCod + Separator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}


	static vector <clsBankClient> _LoadClientDateFromFile()
	{
		fstream MyFile;
		vector<clsBankClient> vClient;

		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Clint = _ConvertLineToClintObject(Line, "#//#");

				vClient.push_back(Clint);
			}

		}
		else
			cout << "Error opening file!" << endl;


		MyFile.close();

		return vClient;
	}

	void _SaveCleintsDataToFile(vector<clsBankClient> vClient)
	{
		fstream MyFile;

		string DateLine;

		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClient)
			{
				if (C._MarkedForDelete == false)
				{
					DateLine = _ConverClientObjectToLine(C);
					MyFile << DateLine << endl;
				}
			}

			MyFile.close();
		}
		else
			cout << "Error opening file!" << endl;

	}

	void _Update()
	{
		vector<clsBankClient>_vClient;
		_vClient = _LoadClientDateFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClient);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}


	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}

	}

	static clsBankClient _GetEmptyClientObject()
	{

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber,
		string PinCod, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCod = PinCod;
		_AccountBalance = AccountBalance;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCod(string PinCod)
	{
		_PinCod = PinCod;
	}

	string GetPineCod()
	{
		return _PinCod;
	}
	__declspec(property(get = GetPineCod, put = SetPinCod))string PinCod;



	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	void Print()
	{
		cout << "\nClient Cart:";
		cout << "\n______________________________";
		cout << "\nFirstName   :" << FirstName;
		cout << "\nLastName    :" << LastName;
		cout << "\nFullName    :" << FullName();
		cout << "\nEmail       :" << Email;
		cout << "\nPhone       :" << Phone;
		cout << "\nAcc. Number :" << _AccountNumber;
		cout << "\nPassword    :" << _PinCod;
		cout << "\nBalance     :" << _AccountBalance;
		cout << "\n______________________________\n";

	}

	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;
		vector<clsBankClient> vClints;

		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Clint = _ConvertLineToClintObject(Line);
				if (Clint.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Clint;
				}

				vClints.push_back(Clint);
			}

			MyFile.clear();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		fstream MyFile;
		vector<clsBankClient> vClints;

		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Clint = _ConvertLineToClintObject(Line);
				if (Clint.AccountNumber() == AccountNumber && Clint.PinCod == PinCode)
				{
					MyFile.close();
					return Clint;
				}

				vClints.push_back(Clint);
			}

			MyFile.clear();

		}

		return _GetEmptyClientObject();
	}


	static bool IsClintExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!(Client.IsEmpty()));
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResult::svFaildEmptyObject;
			}
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClintExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::AddNewMode;
				return enSaveResult::svSucceeded;

			}
		}

		}
	}

	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);

	}

	bool Delete()
	{
		vector<clsBankClient> vClient = _LoadClientDateFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveCleintsDataToFile(vClient);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> GetClientList()
	{
		return _LoadClientDateFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient>vClient = GetClientList();

		double TotalBalances = 0;

		for (clsBankClient C : vClient)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}


	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return true;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	
	
};





