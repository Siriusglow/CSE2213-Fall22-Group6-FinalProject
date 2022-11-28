#include <iostream>
#include <string>
using namespace std;
#include "User.h"
#include "Inv.h"
#include "allUser.h"



int main()             // The entirity of the main function currently is testing. Class implimentation seems to work. 
{
    bool validLogIn = false;
    cout << "Welcome to Penguin Games. The best place for you that we can deliver!" << endl;
    int MenuOption = -1;
    allUsers allUser;
    allUser.fill();

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

                if (allUser.login(loginUsername, loginPassword) != -1) {
                    validLogIn = true;
                }
                else {
                    validLogIn = false;
                }

                if (validLogIn) {
                    cout << "Login sucessful" << endl << endl;
                    // Something to now gather the information based off of the returned userID from earlier. This is how all of the user functions will be created. 
                    cout << "Welcome back to the system" << endl;      // FIXME, maybe a variable to the user.
                    while (MenuOption != 5) {
                        cout << "Please choose a menu option" << endl;
                        cout << "1. View and change user information" << endl;
                        cout << "2. View shopping cart" << endl;
                        cout << "3. Add item to shopping cart" << endl;
                        cout << "4. Remove item to shopping cart" << endl;
                        cout << "5. Logout" << endl;
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
                                        switch (MenuOption) {
                                        case 1:
                                            cout << "FIXME case 1 was chosen" << endl;      // Get rid of switch as it impides the declaration of the class allUsers
                                            break;
                                        case 2:
                                            cout << "FIXME case 2 was called" << endl;
                                            break;
                                        case 3:
                                            cout << "FIXME case 3 was called" << endl;
                                            break;
                                        case 4:
                                            cout << "FIXME case 4 was called" << endl;
                                            break;
                                        case 5:
                                            cout << "FIXME case 5 was called" << endl;
                                            break;
                                        case 6:
                                            cout << "FIXME case 6 was called" << endl;
                                            break;
                                        case 7:
                                            cout << "FIXME case 7 was called" << endl;
                                            break;
                                        default:
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
                                cout << "FIXME Option 2 was chosen" << endl;
                            }
                            else if (MenuOption == 3) {
                                cout << "Below are the items that we have for sale." << endl;
                                Inventory inv1;                                    // FIXME, rename to something more informative.
                                inv1.fill();
                                inv1.display();
                                // Add stuff for adding an item from the inventory to be added to the the shopping cart
                            }
                            else if (MenuOption == 4) {
                                cout << "FIXME Option 4 was chosen" << endl;
                            }
                            else if (MenuOption == 5) {
                                cout << "FIXME Option 5 was chosen" << endl;
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
                    }
                }
                else {
                    cout << "Login Failed. Please try again." << endl;
                }
            }
            else if (MenuOption == 2) {                                 // Add some form of input validation here. In progress to add a new user stuff


                    cout << "FIXME, Add a user was chosen" << endl;
                    int UserId;
                    UserId = allUser.nextID();
                    string name = "";
                    cin.ignore();
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
                    getline(cin, email);
                    
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

                    // FIXME Add Stuff to create a user and add said user to the file here. Also Add Stuff to make this look nice. 

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