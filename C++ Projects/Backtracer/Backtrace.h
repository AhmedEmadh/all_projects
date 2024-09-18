#pragma once
#include <iostream>
#include <vector>
class Backtrace
{
    static std::vector<std::string> backtrace;
public:
    static void pushRecord(const char* funName);
    static void PopRecord();
    static void printAllRecords();
};
#define EnterFn     Backtrace::pushRecord(__func__)
#define ExitFn      Backtrace::PopRecord()
#define PRINT_BT    Backtrace::printAllRecords()



