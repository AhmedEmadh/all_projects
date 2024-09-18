#include "Backtrace.h"

void Backtrace::pushRecord(const char* funName)
{
    std::string rec(funName);
    backtrace.push_back(rec);
    std::cout << "Enter to [" << funName << "]" << std::endl;

}
void Backtrace::PopRecord()
{
    std::cout << "Exit From [" << *(backtrace.end() - 1) << "]" << std::endl;
    backtrace.pop_back();
}
void Backtrace::printAllRecords()
{
    std::cout << "Backtrace as follows : " << std::endl;
    for (int i = 0; i < backtrace.size(); i++)
    {
        std::cout << i << "- " << backtrace[i] << std::endl;
    }
    std::cout << "Backtrace is Finished" << std::endl;
}

std::vector<std::string> Backtrace::backtrace;