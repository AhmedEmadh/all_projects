/*
 ========================================================================================================================================================
 File Name		: clsFindClientScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Find Client Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsFindClientScreen : protected clsScreen
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

public:
	static void ShowFindClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        std::string AccountNumber;
        std::cout << "Please Enter Client Account Number to View: ";
        std::cin >> AccountNumber;
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            std::cout << "The Client is not Exist Please enter it again: ";
            std::cin >> AccountNumber;
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
	}

};