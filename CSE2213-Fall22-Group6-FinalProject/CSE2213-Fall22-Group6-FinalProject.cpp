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
              
                int LoggedinID = allUser.login(loginUsername, loginPassword);

                if (LoggedinID != -1) {
                    validLogIn = true;
                }
                else {
                    validLogIn = false;
                }

                if (validLogIn) {
                    cout << "Login sucessful" << endl << endl;
                    // Something to now gather the information based off of the returned userID from earlier. This is how all of the user functions will be created.
                    User currentUser = allUser.populateUser(LoggedinID);


                    cout << "Welcome back to the system, " << currentUser.getName() << endl;      // FIXME, maybe a variable to the user.
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
                                        if (MenuOption == 1) {
                                            // Nothing needs to go here, as having this input breaks out of the loop and takes you back to the previous menu.
                                        }
                                        else if (MenuOption == 2) {
                                            cout << "Your current payment information: " << endl;
                                            cout << "Credit card number: " << currentUser.getCreditCardNum() << endl;
                                            cout << "Credit card expiration date: " << currentUser.getExpirationDate() << endl;
                                            cout << "Credit card CVV: " << currentUser.getCVV() << endl;

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
                                            cout << "Your current shipping information: " << endl;
                                            cout << "Address: " << currentUser.getAddress() << endl;

                                            string fixedAddress = "";
                                            cout << "Please input your new shipping address: ";
                                            getline(cin, fixedAddress);
                                            currentUser.setAddress(fixedAddress);
                                        }
                                        else if (MenuOption == 4) {
                                            cout << "Your current contact information: " << endl;
                                            cout << "Email: " << currentUser.getEmail() << endl;
                                            cout << "Phone number: " << currentUser.getPhone() << endl;

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
                                            cout << "Your Information: " << endl;
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
                                            cout << "FIXME case 6 was called" << endl;      // FIXME, need order class to be implimented.
                                        }
                                        else if (MenuOption == 7) {                         //FIXME, Michael said he can do.
                                            cout << "FIXME case 7 was called" << endl;
                                        }
                                        else{
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