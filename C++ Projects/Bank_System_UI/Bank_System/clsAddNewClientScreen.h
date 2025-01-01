/*
 ========================================================================================================================================================
 File Name		: clsAddNewClientScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Add new client Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */

#pragma once
#include "clsBankClient.h"
class clsAddNewClientScreen: protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient &Client)
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
	static void ShowAddNewClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
		_DrawScreenHeader("\t Add New Client Screen");
        std::string AccountNumber;
        std::cout << "Please Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            std::cout << "Account Number is Alerady Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                std::cout << "Account Added Successfully :-)" << std::endl;
                _PrintClient(NewClient);
                break;
            }
            case clsBankClient::enSaveResults::svFailedEmptyObject:
            {
                std::cout << "Error Account was not saved because it's Empty";
                break;
            }
        }
	}
};