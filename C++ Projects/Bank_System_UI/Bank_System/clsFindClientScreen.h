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