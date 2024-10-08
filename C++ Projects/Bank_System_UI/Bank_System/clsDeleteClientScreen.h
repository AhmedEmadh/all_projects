#pragma once
#include "clsScreen.h"
class clsDeleteClientScreen : protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
		clsScreen::_DrawScreenHeader("\tDelete Client Screen");
        std::string AccountNumber;
        std::cout << "Please Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            std::cout << "Account number is not fount, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        std::cout << "Are you sure you want to delete this client y/n?";
        char answer = 'n';
        std::cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            if (Client.Delete())
            {
                std::cout << "Client Deleted Successfully"<<std::endl;
            }
            else
            {
                std::cout << "Client Wasn't deleted"<<std::endl;
            }
        }
	}
};