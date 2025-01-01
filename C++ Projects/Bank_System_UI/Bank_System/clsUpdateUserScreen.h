/*
 ========================================================================================================================================================
 File Name		: clsUpdateClientScreen.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Handling Update Client Screen
 Notes			: This Class Inherits from clsScreen to use Methods that are common between all screens
 ========================================================================================================================================================
 */
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsUpdateUserScreen: protected clsScreen
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
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.GetFullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }
public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        std::string UserName = "";
        std::cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            std::cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        std::cout << "\nAre you sure you want to update this User y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            std::cout << "\n\nUpdate User Info:";
            std::cout << "\n____________________\n";

            _ReadUserInfo(User1);
            clsUser::enSaveResults SaveResult;
            SaveResult = User1.Save();
            switch (SaveResult)
            {
            case clsUser::svSucceeded:
            {
                std::cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::svFaildEmptyObject:
            {
                std::cout << "\nError User was not saved because it's Empty";
                break;
            }
            }
        }
    }
};