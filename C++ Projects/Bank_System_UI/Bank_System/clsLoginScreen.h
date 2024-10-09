#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "global.h"
#include <iomanip>
class clsLoginScreen: private clsScreen
{
private:
	static bool _Login()
	{
		std::string UserName, Password;
		bool LoginFailed;
		int loginTrys = 3;
		do
		{
			std::cout << setw(40) << left << "" << "Enter username: ";
			std::cin >> UserName;
			std::cout << setw(40) << left << "" << "Enter Password: ";
			std::cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
			if (LoginFailed)
			{
				std::cout << setw(40) << left << "" << "You have Invalid Username/Password"<<std::endl;
				std::cout << setw(40) << left << "" << "You have "<<--loginTrys<<" Trials to login." << std::endl;
			}
			if (loginTrys < 1)
			{
				std::cout << "\nYou are Locked after 3 faild trails"<<std::endl;
			}
		} while (LoginFailed && loginTrys);
		if(loginTrys)
		{
			clsMainScreen::ShowMainMenue();
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};