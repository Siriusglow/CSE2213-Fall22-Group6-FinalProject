#pragma once
#include "InventoryItem.h"
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;


class Inventory
{
private:
	vector<InventoryItem> itemList;
public:
    vector<InventoryItem> getInv() {
        return itemList;
    }
    ~Inventory()
    {
        ofstream outFile;
        outFile.open("Inventory.txt");
        for (int i = 0; i < itemList.size(); i++)
        {
            outFile << itemList[i].getName() << '\t';
            outFile << itemList[i].getDesc() << '\t';
            outFile << itemList[i].getCost() << '\t';
            outFile << itemList[i].getCount() << '\t';
            outFile << itemList[i].getGenre() << '\t';
            outFile << itemList[i].getPublisher() << '\t';
            outFile << endl;
        }
        outFile.close();
    }
    void setInv(vector<InventoryItem> itemList) {
        this->itemList = itemList;
    }
	void fill()
    {
        itemList.clear();
        ifstream infile;
        infile.open("Inventory.txt");
        string line;

        // Loops
        while (getline(infile, line))
        {
            // Initial Variables
            string name;
            string description;
            double cost;
            int count;
            string genre;
            string publisher;
            string delimiter = "\t";

            name = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            description = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            cost = stod(line.substr(0, line.find(delimiter)));
            line.erase(0, line.find(delimiter) + delimiter.length());
            count = stoi(line.substr(0, line.find(delimiter)));
            line.erase(0, line.find(delimiter) + delimiter.length());
            genre = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            publisher = line.substr(0, line.find(delimiter));


            // Makes a temporary item and then pushes it to the vector
            InventoryItem temp(name, description, cost, count, genre, publisher);
            itemList.push_back(temp);
        }

        infile.close();

	}
    void display()
    {
        // How long you want the display to be
        int width = 50;

        // Sets the numbers to display correctly and right aligns the text

        cout << fixed << right;

        // Makes it pretty
        cout << "---------------------------------------------------------------" << endl;

        // Prints each member variable
        for (unsigned int i = 0; i < itemList.size(); i++)
        {
            string desc = itemList[i].getDesc();
            if (desc.length() > 45)
            {
                desc = "";

                for (int j = 0; j < 46; j++)
                    desc += itemList[i].getDesc()[j];
                desc += "...";
            }

            cout
                << "Index number:" << setw(width) << i << endl
                << "Name        :" << setw(width) << itemList[i].getName() << endl 
                << "Description :" << setw(width) << desc << endl 
                << "Cost        :" << setprecision(2) << setw(width) << itemList[i].getCost() << endl 
                << "Count       :" << setw(width) << itemList[i].getCount() << endl 
                << "Genre       :" << setw(width) << itemList[i].getGenre() << endl 
                << "Publisher   :" << setw(width) << itemList[i].getPublisher() << endl 
                << "---------------------------------------------------------------" << endl;
        }
    }
};