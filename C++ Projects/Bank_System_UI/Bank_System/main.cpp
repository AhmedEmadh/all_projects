//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

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