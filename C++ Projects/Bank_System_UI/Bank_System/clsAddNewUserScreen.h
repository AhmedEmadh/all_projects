/*
 ========================================================================================================================================================
 File Name		: clsAddNewUserScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Add new user Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */

#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsAddNewUserScreen: protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		std::cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		std::cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		std::cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		std::cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		std::cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		std::cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();
	}
	static void _PrintUser(clsUser User)
	{
		std::cout << "\nUser Card:";
		std::cout << "\n___________________";
		std::cout << "\nFirstName   : " << User.GetFirstName();
		std::cout << "\nLastName    : " << User.GetLastName();
		std::cout << "\nFull Name   : " << User.GetFullName();
		std::cout << "\nEmail       : " << User.GetEmail();
		std::cout << "\nPhone       : " << User.GetPhone();
		std::cout << "\nUser Name   : " << User.GetUserName();
		std::cout << "\nPassword    : " << User.GetPassword();
		std::cout << "\nPermissions : " << User.GetPermissions();
		std::cout << "\n___________________\n";

	}
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        std::cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        std::cout << "\nDo you want to give access to : \n ";

        std::cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        std::cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        std::cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        std::cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        std::cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        std::cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        std::cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t  Add New User Screen");
		std::string UserName = "";
		std::cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			std::cout << "\nUserName Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(NewUser);
        NewUser.Save();
        _PrintUser(NewUser);
	}
};