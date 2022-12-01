#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;
#include "User.h"
#include "Inv.h"
#include "Order.h"
#include "allUser.h"
#include "ShoppingCart.h"


int main()             // The entirity of the main function currently is testing. Class implimentation seems to work. 
{
    bool validLogIn = false;
    cout << "Welcome to Penguin Games. The best place for you that we can deliver!" << endl;
    int MenuOption = -1;
    allUsers allUser;
    allUser.fill();
    Inventory inv;
    inv.fill();
    //This will be the Inventory list
    vector<InventoryItem> itemList = inv.getInv();
    //THIS IS A PLACEHOLDER FOR ACTUAL USER SHOPPING CART
    

    while (MenuOption != 3) {
        cout << "Please choose a menu option" << endl;
        cout << "1. Login" << endl;
        cout << "2. Please add a user" << endl;
        cout << "3. Quit" << endl;
        cout << "Menu option: ";
        cin >> MenuOption;
        if (!cin.fail()) {
            if (MenuOption == 1) {
                string loginUsername;
                string loginPassword;
                cout << "Please input your username: ";
                cin >> loginUsername;
                cout << endl;

                cout << "Please input your password: ";
                cin >> loginPassword;
                cout << endl;

                int LoggedinID = allUser.login(loginUsername, loginPassword);

                if (LoggedinID != -1) {
                    validLogIn = true;
                }
                else {
                    validLogIn = false;
                    cout << "Login Failed. Please try agian" << endl;
                }

                if (validLogIn) {
                    ShoppingCart test = ShoppingCart();
                    cout << "Login sucessful" << endl << endl;
                    // Something to now gather the information based off of the returned userID from earlier. This is how all of the user functions will be created.
                    User currentUser = allUser.populateUser(LoggedinID);
                    int DeleteValue = 0; // DeleteValue checks to see if if the account has been deleted. If so, It breaks out off the loop, causing the user to be automatically logged out. Resets upon login to not cause issues.


                    cout << "Welcome back to the system, " << currentUser.getName() << endl;
                    while (MenuOption != 6) {
                        cout << "Please choose a menu option" << endl;
                        cout << "1. View and change user information" << endl;
                        cout << "2. View shopping cart" << endl;
                        cout << "3. Add item to shopping cart" << endl;
                        cout << "4. Remove item to shopping cart" << endl;
                        cout << "5. Checkout" << endl;
                        cout << "6. Logout" << endl;
                        cout << "Menu option: ";
                        cin >> MenuOption; // Validate input FIXME
                        if (!cin.fail()) {
                            if (MenuOption == 1) {
                                MenuOption = -1;
                                while (MenuOption != 1) {
                                    cout << endl << "Please choose a menu option" << endl;
                                    cout << "1. Go Back" << endl;
                                    cout << "2. Edit Payment Information" << endl;
                                    cout << "3. Edit Shipping Informaiton" << endl;
                                    cout << "4. Edit Contact Informaiton" << endl;
                                    cout << "5. View Account Details" << endl;
                                    cout << "6. View Order History" << endl;
                                    cout << "7. Delete Account" << endl;
                                    cout << "Menu option: ";
                                    cin >> MenuOption;
                                    if (!cin.fail()) {
                                        if (MenuOption == 1) {
                                            // Nothing needs to go here, as having this input breaks out of the loop and takes you back to the previous menu.
                                        }
                                        else if (MenuOption == 2) {
                                            cout << endl << "Your current payment information: " << endl;
                                            cout << "Credit card number: " << currentUser.getCreditCardNum() << endl;
                                            cout << "Credit card expiration date: " << currentUser.getExpirationDate() << endl;
                                            cout << "Credit card CVV: " << currentUser.getCVV() << endl << endl;

                                            cin.ignore();
                                            string fixedCreditCardNum = "";
                                            cout << "Please input the new credit card number: ";
                                            getline(cin, fixedCreditCardNum);
                                            currentUser.setCreditCardNum(fixedCreditCardNum);

                                            string fixedExpirationDate = "";
                                            cout << "Please input the new credit card expiration date: ";
                                            getline(cin, fixedExpirationDate);
                                            currentUser.setExpirationDate(fixedExpirationDate);

                                            string fixedCVV = "";
                                            cout << "Please input the new credit card CVV (3 numbers on the back of the card): ";
                                            getline(cin, fixedCVV);
                                            currentUser.setCVV(fixedCVV);
                                        }
                                        else if (MenuOption == 3) {
                                            cout << endl << "Your current shipping information: " << endl;
                                            cout << "Address: " << currentUser.getAddress() << endl << endl;

                                            cin.ignore();
                                            string fixedAddress = "";
                                            cout << "Please input your new shipping address: ";
                                            getline(cin, fixedAddress);
                                            currentUser.setAddress(fixedAddress);
                                        }
                                        else if (MenuOption == 4) {
                                            cout << endl << "Your current contact information: " << endl;
                                            cout << "Email: " << currentUser.getEmail() << endl;
                                            cout << "Phone number: " << currentUser.getPhone() << endl << endl;

                                            cin.ignore();
                                            string fixedEmail = "";
                                            cout << "Please input your new email: ";
                                            getline(cin, fixedEmail);
                                            currentUser.setEmail(fixedEmail);

                                            string fixedPhone = "";
                                            cout << "Please input your new phone number: ";
                                            getline(cin, fixedPhone);
                                            currentUser.setPhone(fixedPhone);

                                        }
                                        else if (MenuOption == 5) {
                                            cout << endl << "Your Information: " << endl;
                                            cout << "\tName: " << currentUser.getName() << endl;
                                            cout << "\tAddress: " << currentUser.getAddress() << endl;
                                            cout << "\tEmail: " << currentUser.getEmail() << endl;
                                            cout << "\tPhone Number: " << currentUser.getPhone() << endl;
                                            cout << "\tCredit Card Number: " << currentUser.getCreditCardNum() << endl;
                                            cout << "\tCredit Card Expiration Date: " << currentUser.getExpirationDate() << endl;
                                            cout << "\tCredit Card CVV Number: " << currentUser.getCVV() << endl;
                                            cout << "\tUsername: " << currentUser.getUsername() << endl;
                                            cout << "\tPassword: " << currentUser.getPassword() << endl;
                                        }
                                        else if (MenuOption == 6) {
                                            vector<Order> orderList;
                                            ifstream infile;
                                            infile.open("testOrder.txt");
                                            string line;
                                            int numOfOrders = 0;

                                            // Loops
                                            cout << "Order History:" << endl << "---------------------------------------------------------------" << endl;
                                            while (getline(infile, line))
                                            {
                                                // Initial Variables
                                                int readOrderID = -1;
                                                int readUserID = 1;
                                                string readUserAddress;
                                                double readTotal = 0.00;
                                                string readDate;
                                                string readNotes;
                                                string delimiter = "\t";

                                                readOrderID = stoi(line.substr(0, line.find(delimiter)));
                                                line.erase(0, line.find(delimiter) + delimiter.length());
                                                readUserID = stoi(line.substr(0, line.find(delimiter)));
                                                line.erase(0, line.find(delimiter) + delimiter.length());
                                                readUserAddress = line.substr(0, line.find(delimiter));
                                                line.erase(0, line.find(delimiter) + delimiter.length());
                                                readTotal = stod(line.substr(0, line.find(delimiter)));
                                                line.erase(0, line.find(delimiter) + delimiter.length());
                                                readDate = line.substr(0, line.find(delimiter));
                                                line.erase(0, line.find(delimiter) + delimiter.length());
                                                readNotes = line.substr(0, line.find(delimiter));
                                                
                                                if (readUserID == LoggedinID) {
                                                    cout
                                                        << "Order Number:" << readOrderID << endl
                                                        << "Address     :" << readUserAddress << endl
                                                        << "Total       :" << readTotal << endl
                                                        << "Date Placed :" << readDate << endl
                                                        << "Notes       :" << readNotes << endl
                                                        << "---------------------------------------------------------------" << endl;
                                                    numOfOrders++;
                                                }
                                            }

                                            if (numOfOrders == 0) {
                                                cout << "No Past Orders" << endl << "---------------------------------------------------------------" << endl;
                                            }

                                            infile.close();

                                        }
                                        else if (MenuOption == 7) {
                                            cout << "Are you sure you want to delete your account? Once you delete your account, you cannot recover your information" << endl;
                                            cout << "1. Yes" << endl;
                                            cout << "2. No" << endl;
                                            cout << "Menu option: ";
                                            try {
                                                cin >> DeleteValue;
                                            }
                                            catch (...) {
                                                cout << "Your menu option was invalid. Please try again" << endl;
                                                cin.clear();
                                                cin.ignore(10000, '\n');
                                            }
                                            if (DeleteValue == 1) {
                                                allUser.deleteUser(LoggedinID);
                                                cout << "Your account has been deleted." << endl;
                                                break;
                                            }
                                            else if (DeleteValue == 2) {
                                                cout << "You have chosen not to delete your account" << endl;
                                            }
                                            else {
                                                cout << "Please choose a valid menu option." << endl;
                                            }
                                        }
                                        else {
                                            cout << "Your option is not valid. Please try again." << endl;
                                        }
                                    }
                                    else {
                                        cout << "Your menu option was invalid. Please choose a number corresponding to one of the options above" << endl;
                                        cin.clear();
                                        cin.ignore(10000, '\n');
                                        cout << endl;
                                    }
                                }
                            }
                            else if (MenuOption == 2) {
                                test.viewCart();
                                MenuOption = -1;
                            }

                            else if (MenuOption == 3) {
                                cout << "Below are the items that we have for sale." << endl;

                                inv.display();
                                // Add stuff for adding an item from the inventory to be added to the the shopping cart
                                int gamenum=-1;
                                cout << "Enter the index of the game you would like to add to your cart:";
                                while (gamenum >= itemList.size() || gamenum < 0) {
                                    cin >> gamenum;
                                    if (gamenum >= itemList.size() || gamenum < 0) {
                                        cout << "Index is either too large or negative. Try Again:";
                                    }
                                }
                                cout << "Enter the number of copies you would like to add to your cart:";
                                int quantity;
                                cin >> quantity;
                                test.addItem(itemList[gamenum], quantity);
                                MenuOption = -1;
                            }
                            else if (MenuOption == 4) {
                                if (test.getCart().size() == 0) {
                                    cout << "Cart is empty, can't remove items yet! Add an item." << endl;
                                    MenuOption = -1;
                                    
                                }
                                else {
                                    test.viewCart();
                                    cout << "Enter the index of the cart item you want to remove from your cart:";
                                    int removenum = -1;
                                    while (removenum >= test.getCart().size() || removenum < 0) {
                                        cin >> removenum;
                                        if (removenum >= test.getCart().size() || removenum < 0) {
                                            cout << "Index is either too large or negative. Try Again:";
                                        }
                                    }
                                    int quantity;
                                    cout << "Enter the number of copies you would like to remove from your cart:";
                                    cin >> quantity;
                                    vector<InventoryItem>removeCart = test.getCart();
                                    test.removeItem(removeCart[removenum], quantity);

                                    MenuOption = -1;
                                }
                            }
                            else if (MenuOption == 5) {
                                vector<InventoryItem> itemsInOrder;
                                itemsInOrder = test.checkout(itemList);
                                inv.setInv(itemList);
                                if (itemsInOrder.size() != 0)
                                {
                                    int orderNum = 1;
                                    string dt = "";
                                    string notesToAdd;

                                    time_t value = time(NULL);
                                    char buff[26];
                                    ctime_s(buff, sizeof buff, &value);
                                    dt = buff;
                                    dt.erase(std::remove(dt.begin(), dt.end(), '\n'), dt.cend());
                                    dt.erase(std::remove(dt.begin(), dt.end(), '\t'), dt.cend());

                                    cout << "The local date and time is: " << dt;
                                    cout << endl << "Write any extra shipping or order notes here: ";
                                    cin.ignore();
                                    getline(cin, notesToAdd);

                                    Order finalOrder = Order(orderNum, LoggedinID, itemsInOrder, currentUser.getAddress(), dt, notesToAdd);

                                }
                                MenuOption = -1;
                            }
                            else if (MenuOption == 6) {
                                allUser.syncAllUser(currentUser);                                                   // if something goes wrong, this is it.
                                cout << endl << "Logout successful. Have a nice day!" << endl;
                            }
                            else {
                                cout << "Your menu option was invalid. Please choose one of the menu options above." << endl;

                            }
                            cout << endl;
                        }
                        else {
                            cout << "Your menu option was invalid. Please choose a number corresponding to one of the options above" << endl;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << endl;
                        }
                        if (DeleteValue == 1) {
                            break;
                        }
                    }
                }
            }
            else if (MenuOption == 2) {                                 // Add some form of input validation here. In progress to add a new user stuff?

                    int UserId;
                    UserId = allUser.nextID();

                    cin.ignore();
                    string name = "";
                    cout << "Please type your full name. A hyphan can be used if you have multiple first names, (ie. Mary-Katherine Smith): ";
                    getline(cin, name);

                    string address = "";
                    cout << "Please type your address. Please include your full address, including city, state, and zip code. Please use an address that can be shipped to." << endl;
                    cout << "Address: ";
                    getline(cin, address);

                    string email = "";
                    cout << "Plase input your email: ";
                    getline(cin, email);

                    string phone = "";
                    cout << "Please input your phone number: ";
                    getline(cin, phone);

                    string CreditCardNum = "";
                    cout << "Please input your credit card number: ";
                    getline(cin, CreditCardNum);

                    string ExpirationDate = "";
                    cout << "Please input the expiration date of your credit card: ";
                    getline(cin, ExpirationDate);

                    string CVV = "";
                    cout << "Please input the CVV of your credit card (the 3 numbers on the back of the card): ";
                    getline(cin, CVV);

                    string Username = "";
                    cout << "Please type in a username for you to use: ";
                    getline(cin, Username);

                    string Password = "";
                    cout << "Please create a password: ";
                    getline(cin, Password);

                    User newUser(UserId, name, address, email, phone, CreditCardNum, ExpirationDate, CVV, Username, Password);
                    allUser.addUser(newUser);
                    // This piece of code does not add the new user to the file. That will be done upon closing.


                }
            else if (MenuOption == 3) {
                    cout << "Thank you for using the system. Have a nice day!" << endl;
                }
            else {
                    cout << "Your menu option was invalid. Please choose one of the menu options above." << endl;
                }
            }
        else {
                cout << "Your input is invalid. Please choose a number corresponding to one of the options above" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << endl;
            }
        cout << endl;
    }
}
