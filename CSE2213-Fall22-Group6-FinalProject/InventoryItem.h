#pragma once

#include <string>
using namespace std;

class InventoryItem
{
private:
	string name;
	string description;
	double cost;
	int count;
	string genre;
	string publisher;

public:

	// Constructor
	InventoryItem(const string& name, const string& desc, const double& cost, const int& count, const string& genre, const string& publisher)
	{
		this->name = name;
		description = desc;
		this->cost = cost;
		this->count = count;
		this->genre = genre;
		this->publisher = publisher;
	}


	// Getters
	string getName()
	{
		return name;
	}
	string getDesc()
	{
		return description;
	}
	double getCost()
	{
		return cost;
	}
	int getCount()
	{
		return count;
	}
	string getGenre()
	{
		return genre;
	}
	string getPublisher()
	{
		return publisher;
	}

	// Setters
	string setName(string value)
	{
		name = value;
	}
	string setDesc(string value)
	{
		description = value;
	}
	double setCost(double value)
	{
		cost = value;
	}
	int setCount(int value)
	{
		count = value;
	}
	string setGenre(string value)
	{
		genre = value;
	}
	string setPublisher(string value)
	{
		publisher = value;
	}
};