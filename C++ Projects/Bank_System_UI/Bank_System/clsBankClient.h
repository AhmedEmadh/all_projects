/*
 ========================================================================================================================================================
 File Name		: clsBankClient.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Bank Client
 Notes			: This class inherits from clsPerson to use its Data Members and Methods
 ========================================================================================================================================================
 */
#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <string>
class clsBankClient : public clsPerson
{
public:
	enum class enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
private:

	enMode _Mode;
	bool _MarkedForDelete = false;
	std::string _AccountNumber;
	std::string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLinetoClientObject(std::string Line, std::string Seperator = "#//#")
	{
		std::vector<std::string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], std::stod(vClientData[6]));

	}
	static std::string _ConvertClientObjectToLine(clsBankClient Client, std::string Seperator = "#//#")
	{
		return (Client.GetFirstName() + Seperator + Client.GetLastName() + Seperator + Client.GetEmail() + Seperator + Client.GetPhone() + Seperator + Client.GetAccountNumber() + Seperator + Client.GetPinCode() + Seperator + std::to_string(Client._AccountBalance));
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static std::vector<clsBankClient> _LoadClientsDataFromFile()
	{
		std::vector<clsBankClient> vClients;
		std::fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			std::string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	void _SaveClientsDataToFile(std::vector<clsBankClient> &vClients)
	{
		std::fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		std::string DataLine;
		if (MyFile.is_open())
		{
			for (auto& Client : vClients)
			{
				if (!Client.MarkedForDelete())
				{
					DataLine = _ConvertClientObjectToLine(Client);
					MyFile << DataLine << std::endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		std::vector <clsBankClient> vClients;
		vClients = _LoadClientsDataFromFile();
		for (auto& Client : vClients)
		{
			if (Client.GetAccountNumber() == _AccountNumber)
			{
				Client = *this;
				break;
			}

		}
		_SaveClientsDataToFile(vClients);
	}
	void _AddDataLineToFile(std::string Line)
	{
		fstream MyFile;
		MyFile.open("clients.txt", std::ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << std::endl;
			MyFile.close();
		}
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
public:
	clsBankClient(enMode Mode, std::string FirstName, std::string LastName, std::string Email, std::string Phone, std::string AccountNumber, std::string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	std::string GetAccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(std::string PinCode)
	{
		_PinCode = PinCode;
	}
	std::string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = GetPinCode)) std::string PinCode;
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	void Deposite(float amount)
	{
		_AccountBalance += amount;
		Save();
	}
	bool Withdraw(float amount)
	{
		if (amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= amount;
			if (Save() == enSaveResults::svSucceeded)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	static clsBankClient Find(std::string AccountNumber)
	{
		std::vector<clsBankClient> vClients;
		std::fstream MyFile;
		MyFile.open("Clients.txt", std::ios::in);//read mode
		if (MyFile.is_open())
		{
			std::string Line;
			while (std::getline(MyFile, Line))
			{
			clsBankClient Client = clsBankClient::_ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(std::string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return !(Client.IsEmpty());
	}
	//void Print()
	//{ No Print inside object (clean code)

	//	std::cout << "____________________" << std::endl;
	//	std::cout << "Client Card:" << std::endl;
	//	std::cout << "____________________" << std::endl;
	//	std::cout << "First Name     : " << GetFirstName() << std::endl;
	//	std::cout << "Last Name      : " << GetLastName() << std::endl;
	//	std::cout << "Full Name      : " << GetFullName() << std::endl;
	//	std::cout << "Email          : " << GetEmail() << std::endl;
	//	std::cout << "Phone          : " << GetPhone() << std::endl;
	//	std::cout << "Acc. Number    : " << _AccountNumber << std::endl;
	//	std::cout << "Password       : " << _PinCode << std::endl;
	//	std::cout << "Balance        : " << _AccountBalance << std::endl;
	//	std::cout << "____________________" << std::endl;
	//}
	enum class enSaveResults { svFailedEmptyObject, svSucceeded, svFaildAccountNumberExists };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				return enSaveResults::svSucceeded;
			}
		}
		}
	}
	static clsBankClient GetAddNewClientObject(std::string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	bool Delete()
	{
		std::vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : _vClients)
		{
			if (Client.GetAccountNumber() == _AccountNumber)
			{
				Client._MarkedForDelete = true;
				continue;
			}
		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}
	static std::vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	static float GetTotalBalances(std::vector<clsBankClient> vClients)
	{
		float TotalBalances = 0;
		for (auto Client : vClients)
		{
			TotalBalances += Client.GetAccountBalance();
		}
		return TotalBalances;
	}
};