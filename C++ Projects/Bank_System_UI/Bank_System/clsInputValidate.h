/*
 ========================================================================================================================================================
 File Name		: clsInputValidate.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is responsible for Validating User Input
 Notes			: This Class Contains Static Methods to Validate User Input
 ========================================================================================================================================================
 */
#pragma once
#include <string>
#include "clsDate.h"
#include "clsUtil.h"
class clsInputValidate
{
public:
	static bool IsNumberBetween(short number, short from, short to)
	{
		if (number >= from and number <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(int number, int from, int to)
	{
		if (number >= from and number <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(float number, float from, float to)
	{
		if (number >= from and number <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(double number, double from, double to)
	{
		if (number >= from and number <= to)
			return true;
		else
			return false;
	}
	static bool IsDateBetween(clsDate date, clsDate date1, clsDate date2)
	{
		//it should work if end > start and start > end
		clsDate& start = (clsDate::IsDate1AfterDate2(date1, date2) || clsDate::IsDate1EqualDate2(date1, date2)) ? date2 : date1;
		clsDate& end = (clsDate::IsDate1AfterDate2(date1, date2) || clsDate::IsDate1EqualDate2(date1, date2)) ? date1 : date2;

		if (clsDate::IsDate1AfterDate2(date, start) and clsDate::IsDate1BeforeDate2(date, end))
		{
			//date is between
			return true;
		}
		else
		{
			//date is not between
			return false;
		}
	}
	static int ReadIntNumber(std::string errorMessage = "The input is invalid, Please write a number again")
	{
		int result;
		while (!(cin >> result))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << errorMessage << std::endl;
		}
		return result;
	}
	static short ReadShortNumber(std::string errorMessage = "The input is invalid, Please write a number again")
	{
		short result;
		while (!(cin >> result))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << errorMessage << std::endl;
		}
		return result;
	}

	static int ReadIntNumberBetween(int start, int end, std::string errorMessage = "The input is invalid, Please write a number again")
	{
		int result;
		result = clsInputValidate::ReadIntNumber();
		while (!clsInputValidate::IsNumberBetween(result, start, end))
		{
			std::cout << errorMessage << std::endl;
			result = clsInputValidate::ReadIntNumber();
		}
		return result;
	}
	
	static short ReadShortNumberBetween(short start, short end, std::string errorMessage = "The input is invalid, Please write a number again")
	{
		short result;
		result = clsInputValidate::ReadShortNumber();
		while (!clsInputValidate::IsNumberBetween(result, start, end))
		{
			std::cout << errorMessage << std::endl;
			result = clsInputValidate::ReadShortNumber();
		}
		return result;
	}
	static double ReadDblNumber(std::string errorMessage = "Error, The Input is not double please Enter a double input: ")
	{
		double result;
		while (!(cin >> result))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << errorMessage << std::endl;
		}
		return result;
	}
	static double ReadDblNumberBetween(double start, double end, std::string errorMessage = "The input is invalid, Please write a number again")
	{
		double result;
		result = clsInputValidate::ReadIntNumber();
		while (!clsInputValidate::IsNumberBetween(result, start, end))
		{
			std::cout << errorMessage << std::endl;
			result = clsInputValidate::ReadIntNumber();
		}
		return result;
	}
	static std::string ReadString()
	{
		std::string  S1 = "";
		std::getline(cin >> ws, S1);
		return S1;
	}
	static bool IsValideDate(clsDate date)
	{
		return date.IsValid();
	}
};