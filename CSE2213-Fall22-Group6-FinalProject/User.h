#pragma once
#include <iostream>
#include <string>
#include "ShoppingCart.h"
using namespace std;

class User
{
private:
	int Userindex;
	int UserId;
	string name;
	string address;
	string email;
	string phone;
	string CreditCardNum;
	string ExpirationDate; 
	string CVV;
	string Username;
	string Password;

public:
	// Constructors and Destructors
	User();
	User(int Userindex, int UserId, string name, string address, string email, string phone, string CreditCardNum, string ExpirationDate, string CVV, string Username, string Password);

	// setters
	void setUserIndex(int Userindex);
	void setName(string name);
	void setAddress(string address);
	void setEmail(string email);
	void setPhone(string phone);					// changed in name from the design document to simplify.
	void setCreditCardNum(string CreditCardNum);
	void setExpirationDate(string ExpirationDate);
	void setCVV(string CVV);
	void setUsername(string Username);
	void setPassword(string Password);

	//getters
	int getUserIndex();
	int getID();
	string getName();
	string getAddress();
	string getEmail();
	string getPhone();
	string getCreditCardNum();
	string getExpirationDate();
	string getCVV();
	string getUsername();
	string getPassword();

};

