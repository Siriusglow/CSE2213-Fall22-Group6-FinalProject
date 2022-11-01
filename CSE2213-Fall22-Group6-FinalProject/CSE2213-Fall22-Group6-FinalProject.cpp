#include <iostream>
#include <string>
#include "User.h"
using namespace std;

bool login();

int main()                                                                  // The entirity of the main function currently is testing. Class implimentation seems to work. 
{
    bool validLogIn = false;
    cout << "Welcome to Penguin Games. The best place for you that we can deliver!" << endl;
    int MenuOption = -1;

    while (MenuOption != 3) {
        cout << "Please choose a menu option" << endl;
        cout << "1. Login" << endl;
        cout << "2. Please add a user" << endl;
        cout << "3. Quit" << endl;
        cout << "Menu option: ";
        cin >> MenuOption;
        if (!cin.fail()) {
            if (MenuOption == 1) {
                validLogIn = login();
                if (validLogIn) {
                    cout << "Login sucessful" << endl << endl;
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
                                            cout << "FIXME case 1 was chosen" << endl;
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
                                cout << "FIXME Option 3 was chosen" << endl;
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
            else if (MenuOption == 2) {
                cout << "FIXME, Add a user was chosen" << endl;
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

bool login(){
    return true;        // FIXME. This is true currently for testing purposes.
}
