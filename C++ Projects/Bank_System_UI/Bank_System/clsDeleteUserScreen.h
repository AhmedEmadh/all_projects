/*
 ========================================================================================================================================================
 File Name		: clsDeleteUserScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Delete User Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsDeleteUserScreen: protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.GetFullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }
public:
	static void ShowDeleteUserScreen()
	{
        _DrawScreenHeader("\tDelete User Screen");
        std::string UserName = "";
        std::cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            std::cout << "]nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);
        std::cout << "\nAre you sure you want to delete this User y/n? ";
        char Answer;
        std::cin >> Answer;
        if(Answer == 'y' || Answer == 'Y')
        {
            if (User1.Delete())
            {
                std::cout << "\nUserDeleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                std::cout << "\nError User Was not Deleted\n";
            }
        }
	}
};