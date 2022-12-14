#include "User.h"

User::User() {
	Userindex = 0;
	UserId = 0;
	name = "";
	address = "";
	email = "";
	phone = "";
	CreditCardNum = "";
	ExpirationDate = "";
	CVV = "";
	Username = "";
	Password = "";
}

User::User(int Userindex, int UserId, string name, string address, string email, string phone, string CreditCardNum, string ExpirationDate, string CVV, string Username, string Password) {	// FIXME, should we keep UserId?
	this->Userindex = Userindex;
	this->UserId = UserId;
	this->name = name;
	this->address = address;
	this->email = email;
	this->phone = phone;
	this->CreditCardNum = CreditCardNum;
	this->ExpirationDate = ExpirationDate;
	this->CVV = CVV;
	this->Username = Username;
	this->Password = Password;
}

void User::setUserIndex(int Userindex) {
	this->Userindex = Userindex;
}

void User::setName(string name) {
	this->name = name;
}

void User::setAddress(string address) {
	this->address = address;
}

void User::setEmail(string email) {
	this->email = email;
}

void User::setPhone(string phone) {
	this->phone = phone;
}

void User::setCreditCardNum(string CreditCardNum) {
	this->CreditCardNum = CreditCardNum;
}

void User::setExpirationDate(string ExpirationDate) {
	this->ExpirationDate = ExpirationDate;
}

void User::setCVV(string CVV) {
	this->CVV = CVV;
}

void User::setUsername(string Username) {
	this->Username = Username;
}

void User::setPassword(string Password) {
	this->Password = Password;
}

string User::getName() {
	return name;
}

string User::getAddress() {
	return address;
}

string User::getEmail() {
	return email;
}

string User::getPhone() {
	return phone;
}

string User::getCreditCardNum() {
	return CreditCardNum;
}

string User::getExpirationDate() {
	return ExpirationDate;
}

string User::getCVV() {
	return CVV;
}

string User::getUsername() {
	return Username;
}

string User::getPassword() {
	return Password;
}

int User::getID() {
	return UserId;
}

int User::getUserIndex() {
	return Userindex;
}
