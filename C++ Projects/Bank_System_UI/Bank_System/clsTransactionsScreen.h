/*
 ========================================================================================================================================================
 File Name		: clsTransactionsScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Transactions Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clstotalBalancesScreen.h"
class clsTransactionsScreen : protected clsScreen
{
private:
	enum class enTransactionsMenueOptions
	{
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4
	};
	static void _ShowDepositScreen()
	{
		//std::cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		//std::cout << "\n Withdraw Screen will be here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen()
	{
		//std::cout << "\n Balances Screen will be here.\n";
		clstotalBalancesScreen::ShowTotalBalances();
	}
	static short _ReadTransactionMenueOption()
	{
		std::cout << setw(37) << left << "" << "Choose what do you want to do? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4);
		return Choice;
	}
	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _PerformTransactionScreenOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case clsTransactionsScreen::enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::enTransactionsMenueOptions::eShowMainMenue:
		{
			//Do nothing here the main screen will handle it
			break;
		}
		default:
		{
			break;
		}
		}
	}
public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
			system("pause>0");
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("\tTransactions Screen");
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		std::cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		std::cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		std::cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionScreenOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());

	}
};