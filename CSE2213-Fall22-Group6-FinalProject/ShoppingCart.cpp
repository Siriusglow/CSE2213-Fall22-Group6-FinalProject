//
// Created by jerem on 8/11/2022.
//

#include "ShoppingCart.h"
#include "Inv.h"

// MAYBE SHOULDN'T HAVE A DEFAULT
ShoppingCart::ShoppingCart(){
    UserId = 0;
}

ShoppingCart::ShoppingCart(int UserID){
    this->UserId = UserID;
}

// LET ME KNOW WHEN YOU FINISH THE REST OF THIS SO I CAN MAKE THIS WORK
ShoppingCart::~ShoppingCart(){
    cout<<"Shopping Cart Destructor Called"<<endl;
}


// PROBABLY SHOULDN'T CHANGE
void ShoppingCart::setUserID(int id){
    this->UserId = id;
}

int ShoppingCart::getUserID() {
    return UserId;
}

vector<InventoryItem> ShoppingCart::getCart() {
    return Items;
}

// MAKE SURE THAT YOU ONLY HAVE 1 INSTANCE OF EACH ITEM. MAKES COUNTING EASIER LATER
void ShoppingCart::addItem(InventoryItem item, int quantity)
{
    
    if (quantity < 1 || item.getCount() < quantity) {
        cout << "item quantity is invalid" << endl;
        return;
    }
    for (int i = 0;i < Items.size();i++) {
        if (Items[i].getName() == item.getName()) {
            Items[i].setCount(Items[i].getCount() + quantity);
            cout << "Item added successfully!" << endl;
            return;
        }
    }
    InventoryItem temp = item;
    temp.setCount(quantity);
    
    Items.push_back(temp);
    cout << "Item added successfully!" << endl;
    
}

// MAKE SURE THAT ITEMS NEVER DROP BELOW 0 AND THAT COUNTS ARE VALID
// BEST WAY TO DO THIS IS PROBABLY TO CHECK IF QUANTITY >= COUNT AND THEN SUBTRACT THEM.
// THEN AFTER EVERY REMOVE CHECK IF THERE IS A ZERO. IF THERE IS, REMVOE IT.
void ShoppingCart::removeItem(InventoryItem item, int quantity)
{
    if (quantity < 1) {
        cout << "quantity removed cannot be less than 0" << endl;
        return;
    }
    
    for (int i = 0;i < Items.size();i++) {
        if (item.getName() == Items[i].getName()) {
            //if quantity exceeds
            if (quantity > Items[i].getCount()) {
                cout << "Quantity exceeds items in cart." << endl;
                return;
            }
            //if the whole item quantity is being removed
            if (quantity == Items[i].getCount()) {
                Items.erase(Items.begin() + i);
                cout << "Item removed successfully from cart" << endl;
                return;
            }
            Items[i].setCount(Items[i].getCount() - quantity);
            cout << "Item removed successfully from cart" << endl;
        }
    }
}


void ShoppingCart::viewCart()
{
    if (Items.size() == 0) {
        cout << "Cart is currently empty" << endl;
        return;
    }
    // How long you want the display to be
    int width = 50;

    // Sets the numbers to display correctly and right aligns the text

    cout << fixed << right;

    // Makes it pretty
    cout << "--------------------------Cart---------------------------------" << endl;

    // Prints each member variable
    for (unsigned int i = 0; i < Items.size(); i++)
    {
        string desc = Items[i].getDesc();
        if (desc.length() > 45)
        {
            desc = "";

            for (int j = 0; j < 46; j++)
                desc += Items[i].getDesc()[j];
            desc += "...";
        }

        cout
            << "Index number:" << setw(width) << i << endl
            << "Name        :" << setw(width) << Items[i].getName() << endl
            << "Description :" << setw(width) << desc << endl
            << "Cost        :" << setprecision(2) << setw(width) << Items[i].getCost() << endl
            << "Count       :" << setw(width) << Items[i].getCount() << endl
            << "Genre       :" << setw(width) << Items[i].getGenre() << endl
            << "Publisher   :" << setw(width) << Items[i].getPublisher() << endl
            << "---------------------------------------------------------------" << endl;
    }
}


void ShoppingCart::clearCart()
{
    Items.clear();
}

// MAKE SURE THAT YOU ARE THINKING OF HOW THE ORDER WILL RECEIVE YOUR DATA. 
// THE EASIEST WAY FOR THEM IS GOING TO BE A VECTOR OF INVENTORY ITEMS
vector<InventoryItem> ShoppingCart::checkout(vector<InventoryItem> &itemList)
{
    int num;
    int counter=0;
    if (Items.size() == 0) {
        cout << "Cart is empty, couldn't checkout" << endl;
        return Items;
    }
    for (int i = 0;i < Items.size();i++) {
        for (int j = 0;j < itemList.size();j++) {
            if (Items[i].getName() == itemList[j].getName()) {
                if (Items[i].getCount() > itemList[j].getCount()) {
                    cout << "Checkout was not successful, cart has been emptied" << endl;
                    Items.clear();
                    vector<InventoryItem> temp;
                    return temp;
                }
             
            }
            
        }
    }

    for (int i = 0;i < Items.size();i++) {
        for (int j = 0;j < itemList.size();j++) {
            if (Items[i].getName() == itemList[j].getName()) {
                num = itemList[j].getCount() - Items[i].getCount();
                itemList[j].setCount(num);
            }
        }
    }
    //remove all items from the inventory that have count of 0
    for (vector<InventoryItem>::iterator it = itemList.begin();it != itemList.end();)
    {

        if (it->getCount() == 0)
            it = itemList.erase(it);
        else
            ++it;
    }
    vector<InventoryItem> temp = Items;
    Items.clear();
    
    cout << "Checking out..." << endl;
    return temp;
}

