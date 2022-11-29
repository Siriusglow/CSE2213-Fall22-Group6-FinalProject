#include "Order.h"

Order::Order() {
	orderNumber = -1; //Changed to default userID for not being logged in
	userID = 0;
	itemList = vector<InventoryItem>();
	total = 0.00;
	itemCount = 0;
	shippingAddress = "";
	datePlaced = "";
	extraNotes = "";
}

Order::Order(int orderNumber, int userID, vector<InventoryItem> itemList, double total, string shippingAddress, string datePlaced, string extraNotes) {
	this->orderNumber = orderNumber;
	this->userID = userID;
	this->itemList = itemList;
	this->total = total;
	this->itemCount = itemCount;
	this->shippingAddress = shippingAddress;
	this->datePlaced = datePlaced;
	this->extraNotes = extraNotes;
}

Order::~Order() {
	cout << "FIXME Destructor Called" << endl;
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
	itemCount++;
}

void Order::addNote(string note) {
	this->extraNotes += " - " + note;
}
