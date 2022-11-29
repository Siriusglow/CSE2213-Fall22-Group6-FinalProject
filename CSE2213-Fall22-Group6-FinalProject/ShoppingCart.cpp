//
// Created by jerem on 8/11/2022.
//

#include "ShoppingCart.h"


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

// MAKE SURE THAT YOU ONLY HAVE 1 INSTANCE OF EACH ITEM. MAKES COUNTING EASIER LATER
void ShoppingCart::addItem(InventoryItem item, int quantity)
{

}

// MAKE SURE THAT ITEMS NEVER DROP BELOW 0 AND THAT COUNTS ARE VALID
// BEST WAY TO DO THIS IS PROBABLY TO CHECK IF QUANTITY >= COUNT AND THEN SUBTRACT THEM.
// THEN AFTER EVERY REMOVE CHECK IF THERE IS A ZERO. IF THERE IS, REMVOE IT.
void ShoppingCart::removeItem(InventoryItem item, int quantity)
{

}


void ShoppingCart::viewCart()
{

}


void ShoppingCart::clearCart()
{

}

// MAKE SURE THAT YOU ARE THINKING OF HOW THE ORDER WILL RECEIVE YOUR DATA. 
// THE EASIEST WAY FOR THEM IS GOING TO BE A VECTOR OF INVENTORY ITEMS
void ShoppingCart::checkout()
{

}

