//James Was Here

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "InventoryItem.h"
#include "Inv.h"
using namespace std;

class Order
{
private:
	int orderNumber;
	int userID;
	vector<InventoryItem> itemList;
	double total;
	int itemCount;
	string shippingAddress;
	string datePlaced;
	string extraNotes;
public:
	Order();
	Order(int orderNumber, int userID, vector<InventoryItem> itemList, string shippingAddress, string datePlaced, string extraNotes);
	~Order();

	void setUserID(int id);
	void setShippingAddress(string address);

	int getOrderNum();
	int getUserID();
	double getTotal();
	string getShippingAddress();
	string getNotes();
	
	void calculateTotal();
	void addItem(InventoryItem item);
	void addNote(string note);
};

