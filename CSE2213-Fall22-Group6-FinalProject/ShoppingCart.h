//
// Created by jerem on 8/11/2022.
//

#ifndef CSE2213_FALL22_GROUP6_FINALPROJECT_CART_H
#define CSE2213_FALL22_GROUP6_FINALPROJECT_CART_H
#pragma once
#include <iostream>
#include <string>
using namespace std;

class ShoppingCart
{
private:
    int UserId;

public:
    // Constructors and Destructors
    ShoppingCart();
    ShoppingCart(int UserId);
    ~ShoppingCart();

    //getter
    int getUserID(int id);

    // setter
    void setUserID(int id);

    void addItem(InventoryItem item, int quantity);
    void removeItem(InventoryItem item);
    void viewCart();
    void clearCart();
    void checkout();
};



#endif //CSE2213_FALL22_GROUP6_FINALPROJECT_CART_H
