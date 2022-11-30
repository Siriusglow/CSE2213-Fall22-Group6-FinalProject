#pragma once
#include "User.h"
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;


class allUsers
{
private:
    vector<User> userList;
public:
    void fill()
    {
        userList.clear();
        ifstream infile;
        infile.open("Users.txt");
        if (infile.is_open())
            cout << "Opened\n";
        string line;

        // FIXTHISWHY

        // Loops
        while (getline(infile, line))
        {
            // Initial Variables
            int UserId;
            string name;
            string address;
            string email;
            string phone;
            string CreditCardNum;
            string ExpirationDate;
            string CVV;
            string Username;
            string Password;

            string delimiter = "\t";

            UserId = stoi(line.substr(0, line.find(delimiter)));
            line.erase(0, line.find(delimiter) + delimiter.length());
            name = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            address = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            email = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            phone = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            CreditCardNum = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            ExpirationDate = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            CVV = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            Username = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            Password = line.substr(0, line.find(delimiter));

            cout << "Temp name : " << name << endl;

            // Makes a temporary item and then pushes it to the vector
            User temp(UserId, name, address, email, phone, CreditCardNum, ExpirationDate, CVV, Username, Password);
            userList.push_back(temp);
        }

        infile.close();

    }
    void display()
    {
        // How long you want the display to be
        int width = 50;

        // Sets the numbers to display correctly and right aligns the text

        cout << fixed << right;

        cout << "SIZE : " << userList.size() << endl;
        // Makes it pretty
        cout << "---------------------------------------------------------------" << endl;

        // Prints each member variable
        for (unsigned int i = 0; i < userList.size(); i++)
        {

            cout
                << "Name       :" << setw(width) << userList[i].getName() << endl
                << "Address    :" << setw(width) << userList[i].getAddress() << endl
                << "Email      :" << setw(width) << userList[i].getEmail() << endl
                << "Phone      :" << setw(width) << userList[i].getPhone() << endl
                << "CCN        :" << setw(width) << userList[i].getCreditCardNum() << endl
                << "Exp        :" << setw(width) << userList[i].getExpirationDate() << endl
                << "CVV        :" << setw(width) << userList[i].getCVV() << endl
                << "Username   :" << setw(width) << userList[i].getUsername() << endl
                << "Password   :" << setw(width) << userList[i].getPassword() << endl
                << "---------------------------------------------------------------" << endl;
        }
    }

    int login(string username, string password)
    {
        for (unsigned int i = 0; i < userList.size(); i++)
        {
            if (userList[i].getUsername() == username && userList[i].getPassword() == password)
                return userList[i].getID();
        }
        return -1;
    }

    // Added this. Returns the total number of users. Because our count starts at zero, this will also be the next available UserID.
    int nextID() {        
        return userList.size();
    }

    void addUser(User user) {
        userList.push_back(user);
    }

    User populateUser(int UserId) {
        return userList.at(UserId);
    }

    void deleteUser(int UserId) {
        userList.erase(userList.begin() + UserId);
    }

};