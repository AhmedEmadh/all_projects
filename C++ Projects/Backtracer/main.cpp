#include <iostream>
#include <string>
#include <vector>
#include "Backtrace.h"
void fun1(int x);
void fun2(int x);
void fun3(int x);

int main()
{
    EnterFn;
    fun1(3);
    ExitFn;
    return 0;
}

void fun1(int x)
{
    EnterFn;
    fun2(2);
    ExitFn;
}
void fun2(int x)
{
    EnterFn;
    fun3(3);
    ExitFn;
}
void fun3(int x)
{
    EnterFn;
    PRINT_BT;
    ExitFn;
}