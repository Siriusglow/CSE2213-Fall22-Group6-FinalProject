//
// Created by jerem on 8/11/2022.
//

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    UserID = 0;
    vector<InventoryItem> Items;
}

ShoppingCart::ShoppingCart(UserID){
    this->UserID = UserID;
    vector<InventoryItem> Items;
}

ShoppingCart::~ShoppingCart(){
    cout<<"Shopping Cart Destructor Called"<<endl;
}

void ShoppingCart::setUserID(int id){
    this->UserID = id;
}

int ShoppingCart::getUserID() {
    return UserID;
}

void ShoppingCart::additem(InventoryItem item, int quantity){
}
void ShoppingCart::removeitem(string name){
}
void ShoppingCart::viewCart(){
}
void ShoppingCart::clearCart(){
}
void ShoppingCart::checkout(){
}

