/*
 ========================================================================================================================================================
 File Name		: main.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This File is the Entry Point of the Bank System
 Notes			: This File Contains the Main Function
 ========================================================================================================================================================
 */

#include "clsLoginScreen.h"
int main()
{
    //ViewClient();
    //AddNewClient();
    //UpdateClient();
    //DeleteClient();
    //ShowClientsList();
    //ShowTotalBalances();
    //system("pause");
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }
    //clstotalBalancesScreen::ShowTotalBalances();
    return 0;
}