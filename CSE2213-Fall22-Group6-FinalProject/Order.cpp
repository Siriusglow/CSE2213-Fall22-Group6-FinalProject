#include "Order.h"

Order::Order() {
	orderNumber = -1; //Changed to default userID for not being logged in
	userID = 0;
	itemList = vector<InventoryItem>();
	total = 0.00;
	shippingAddress = "";
	datePlaced = "";
	extraNotes = "";
}

Order::Order(int orderNumber, int userID, vector<InventoryItem> itemList, string shippingAddress, string datePlaced, string extraNotes) {
	this->orderNumber = orderNumber;
	this->userID = userID;
	this->itemList = itemList;
	this->shippingAddress = shippingAddress;
	this->datePlaced = datePlaced;
	this->extraNotes = extraNotes;
	calculateTotal();
}

Order::~Order() {
	ofstream outFile("Orders.txt", std::ios_base::app);;
	outFile << "\n";
	outFile << orderNumber << '\t';
	outFile << userID << '\t';
	outFile << shippingAddress << '\t';
	outFile << total << "\t";
	outFile << datePlaced << '\t';
	outFile << extraNotes << '\t';

	for (int i = 0; i < itemList.size(); i++)
	{
		if (i != 0)
		{
			outFile << "|";
		}
		outFile << itemList[i].getName() << '-';
		outFile << itemList[i].getCost() << '-';
		outFile << itemList[i].getCount();
	}

	outFile.close();
}

void Order::setUserID(int id) {
	this->userID = id;
}

void Order::setShippingAddress(string address) {
	this->shippingAddress = address;
}

int Order::getOrderNum() {
	return orderNumber;
}

int Order::getUserID() {
	return userID;
}

double Order::getTotal() {
	calculateTotal();
	return total;
}

string Order::getShippingAddress() {
	return shippingAddress;
}

string Order::getNotes() {
	return extraNotes;
}

void Order::calculateTotal() {
	double temptotal = 0;
	for (int i = 0; i < this->itemList.size(); i++) {
		temptotal += this->itemList[i].getCost() * this->itemList[i].getCount();
	}
	this->total = temptotal;
}

void Order::addItem(InventoryItem item) {
	itemList.push_back(item);
}

void Order::addNote(string note) {
	this->extraNotes += note;
}
