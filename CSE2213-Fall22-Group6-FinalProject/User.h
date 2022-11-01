#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string name;

public:
	void setName(string name);	// test setter

	string getName();	//test getter
};

