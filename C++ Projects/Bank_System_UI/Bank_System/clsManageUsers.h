/*
 ========================================================================================================================================================
 File Name		: clsManageUsers.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Manage Users Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsers: protected clsScreen
{
	static void _GoBackToManageUsers()
	{
		cout << setw(37) << left << "" << "\nPress any key to go back to Manage Users Menue...\n";
		system("pause>0");
		system("cls");
		ShowManageUsersScreen();
	}
	static void _ShowListUsersScreen()
	{
		//std::cout << "List Users Screen Will be here" << std::endl;
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		//std::cout << "Add New User Screen Will be here" << std::endl;
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		//std::cout << "Delete User Screen Will be here" << std::endl;
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		//std::cout << "Update User Screen Will be here" << std::endl;
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		//std::cout << "Find User Screen Will be here" << std::endl;
		clsFindUserScreen::ShowFindUserScreen();
	}
	enum class ManageUsersOptions{enListUsers = 1,enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4,enFindUser = 5, MainMenue = 6};
	static void _PerformOption(ManageUsersOptions Option)
	{
		switch (Option)
		{
		case ManageUsersOptions::enListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsers();
			break;
		}
		case ManageUsersOptions::enAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_ShowAddNewUserScreen();
			_GoBackToManageUsers();
			break;
		}
		case ManageUsersOptions::enDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsers();
			break;
		}
		case ManageUsersOptions::enUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsers();
			break;
		}
		case ManageUsersOptions::enFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsers();
			break;
		}
		case ManageUsersOptions::MainMenue:
		{
			//Do nothing here the Main menue will handle it
			break;
		}
		}
	}
public:
	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
			system("pause>0");
			return;
		}
		_DrawScreenHeader("\tManage Users Screen");
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t\t\tManage Users Menue\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] List Users.\n";
		std::cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		std::cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		std::cout << setw(37) << left << "" << "\t[4] Update User.\n";
		std::cout << setw(37) << left << "" << "\t[5] Find User.\n";
		std::cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		_PerformOption(static_cast<ManageUsersOptions>(clsInputValidate::ReadShortNumberBetween(1, 6)));

	}
};