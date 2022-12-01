//
// Created by jerem on 8/11/2022.
//

#ifndef CSE2213_FALL22_GROUP6_FINALPROJECT_CART_H
#define CSE2213_FALL22_GROUP6_FINALPROJECT_CART_H
#pragma once
#include <iostream>
#include <string>
#include "Inv.h"
#include "algorithm"

using namespace std;

class ShoppingCart
{
private:
    int UserId;
    vector<InventoryItem> Items;

public:
    // Constructors and Destructors
    ShoppingCart();
    ShoppingCart(int UserId);


    //getter
    int getUserID();

    vector<InventoryItem> getCart();

    // setter
    void setUserID(int id);

    void addItem(InventoryItem, int);
    void removeItem(InventoryItem, int);
    void viewCart();
    void clearCart();
    vector<InventoryItem> checkout(vector<InventoryItem>&);
};



#endif //CSE2213_FALL22_GROUP6_FINALPROJECT_CART_H
