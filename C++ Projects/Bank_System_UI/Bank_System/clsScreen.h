/*
 ========================================================================================================================================================
 File Name		: clsScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is the Base Class for all Screens in the Bank System
 Notes			: This Class Contains Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include <iostream>
#include "clsUser.h"
#include "global.h"
#include "clsDate.h"
class clsScreen
{
protected:
	static void _DrawScreenHeader(std::string Title, std::string SubTitle = "")
	{
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            std::cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
        std::cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << std::endl;
        std::cout << "\t\t\t\t\tDate: " << clsDate().DateToString() << '\n' << std::endl;
	}
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            std::cout << "\t\t\t\t\t______________________________________";
            std::cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            std::cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};