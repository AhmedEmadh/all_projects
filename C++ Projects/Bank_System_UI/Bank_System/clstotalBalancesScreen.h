/*
 ========================================================================================================================================================
 File Name		: clstotalBalancesScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Total Balances Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
class clstotalBalancesScreen: protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		std::cout << setw(25) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
		std::cout << "| " << setw(40) << left << Client.GetFullName();
		std::cout << "| " << setw(12) << left << Client.GetAccountBalance();
	}
public:
    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        std::cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        std::cout << "__________________________\n" << endl;

        std::cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        std::cout << "| " << left << setw(40) << "Client Name";
        std::cout << "| " << left << setw(12) << "Balance";
        std::cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        std::cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances(vClients);

        if (vClients.size() == 0)
            std::cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                std::cout << endl;
            }

        std::cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        std::cout << "__________________________\n" << endl;

        std::cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        std::cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }

};