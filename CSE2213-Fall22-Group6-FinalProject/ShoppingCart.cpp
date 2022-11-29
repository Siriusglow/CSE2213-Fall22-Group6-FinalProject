//
// Created by jerem on 8/11/2022.
//

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    UserId = 0;
    vector<InventoryItem> Items;
}

ShoppingCart::ShoppingCart(int UserID){
    this->UserId = UserID;
    vector<InventoryItem> Items;
}

ShoppingCart::~ShoppingCart(){
    cout<<"Shopping Cart Destructor Called"<<endl;
}

void ShoppingCart::setUserID(int id){
    this->UserId = id;
}

int ShoppingCart::getUserID() {
    return UserId;
}

void ShoppingCart::addItem(InventoryItem item, int quantity)
{

}
void ShoppingCart::removeItem(InventoryItem item, int quantity)
{

}
void ShoppingCart::viewCart()
{

}
void ShoppingCart::clearCart()
{

}
void ShoppingCart::checkout()
{

}

