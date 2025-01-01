/*
 ========================================================================================================================================================
 File Name		: clsWithdrawScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Withdraw Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include "clsScreen.h"
class clsWithdrawScreen: protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{

		std::cout << "____________________" << std::endl;
		std::cout << "Client Card:" << std::endl;
		std::cout << "____________________" << std::endl;
		std::cout << "First Name     : " << Client.GetFirstName() << std::endl;
		std::cout << "Last Name      : " << Client.GetLastName() << std::endl;
		std::cout << "Full Name      : " << Client.GetFullName() << std::endl;
		std::cout << "Email          : " << Client.GetEmail() << std::endl;
		std::cout << "Phone          : " << Client.GetPhone() << std::endl;
		std::cout << "Acc. Number    : " << Client.GetAccountNumber() << std::endl;
		std::cout << "Password       : " << Client.GetPinCode() << std::endl;
		std::cout << "Balance        : " << Client.GetAccountBalance() << std::endl;
		std::cout << "____________________" << std::endl;

	}
	static std::string _ReadAccountNumber()
	{
		std::string AccountNumber;
		std::cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");
		std::string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			std::cout << "\nClient with [" << AccountNumber << "] is not exist please Enter another one: ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double amount;
		std::cout << "Please Enter Withdraw Amount: ";
		amount = clsInputValidate::ReadDblNumber();
		std::cout << "Are you sure that you want to Withdraw " << amount << " ? ";
		char choice;
		std::cin >> choice;
		if (choice == 'y' or choice == 'Y')
		{
			if (Client.Withdraw(amount))
			{
				std::cout << "Amount withdrawed successfully\n";
				std::cout << "New Balance is " << Client.GetAccountBalance() << std::endl;
			}
			else
			{
				std::cout << "Cannot Withdraw insuffecient Balance!"<<std::endl;
			}
		}
		else
		{
			std::cout << "Operation is cancled";
		}
	}
};