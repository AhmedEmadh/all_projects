/*
 ========================================================================================================================================================
 File Name		: clsPerson.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 12/10/2024
 Description	: This Class is the Base Class for all Users and Clients in the Bank System
 Notes			: This Class Contains Data Members and Methods that are common between all Users and Clients
 ========================================================================================================================================================
 */
#pragma once
#include <iostream>
#include <string>
class clsPerson
{
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _Phone;
public:
	clsPerson(std::string FirstName, std::string LastName, std::string Email, std::string Phone) :_FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone) {}
	std::string GetFirstName()
	{
		return _FirstName;
	}
	std::string GetLastName()
	{
		return _LastName;
	}
	std::string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) std::string Email;
	std::string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) std::string Phone;
	std::string GetFullName()
	{
		return _FirstName + " " + _LastName;
	}
	void SetFirstName(std::string FirstName)
	{
		_FirstName = FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) std::string FirstName;
	void SetLastName(std::string LastName)
	{
		_LastName = LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) std::string LastName;
	void SetEmail(std::string Email)
	{
		_Email = Email;
	}
	void SetPhone(std::string Phone)
	{
		_Phone = Phone;
	}
};