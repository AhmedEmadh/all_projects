/*
 ========================================================================================================================================================
 File Name		: clsUpdateClientScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Total Balances Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include "clsScreen.h"
class clsUpdateClientScreen: protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& Client)
    {
        std::string tempStr;
        float tempFloat;
        std::cout << "Enter FirstName: ";
        std::cin >> tempStr;
        Client.SetFirstName(tempStr);
        std::cout << "Enter LastName: ";
        std::cin >> tempStr;
        Client.SetLastName(tempStr);
        std::cout << "Enter Email: ";
        std::cin >> tempStr;
        Client.SetEmail(tempStr);
        std::cout << "Enter Phone: ";
        std::cin >> tempStr;
        Client.SetPhone(tempStr);
        std::cout << "Enter PinCode: ";
        std::cin >> tempStr;
        Client.SetPinCode(tempStr);
        std::cout << "Enter Account Balance: ";
        std::cin >> tempFloat;
        Client.SetAccountBalance(tempFloat);
    }

public:
	static void ShowUpdateClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
        _DrawScreenHeader("\tUpdate Client Screen");
        std::cout << "Please Enter Account Number: ";
        std::string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            std::cout << "Account number is not found, choose another one: ";
            cin >> AccountNumber;
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        std::cout << "Update Client Info:\n";
        std::cout << "____________________\n";
        _ReadClientInfo(Client);
        Client.Save();
        std::cout << "Account Updated Successsfully :-)" << std::endl;
        _PrintClient(Client);
	}
};