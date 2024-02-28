// Copyright 
#include "Inventory.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::cin;
using std::endl;


// Create some initial inventory items
void initializeInventory(std::vector<Inventory>& inv) {
    // Create two instances specifying all instance variables
    inv.push_back(Inventory(1, "Item A", 10, 15.99));
    inv.push_back(Inventory(2, "Item B", 5, 24.99));
    // Create an empty instance and use setters to initialize
    inv.push_back(Inventory());
    size_t invSize = inv.size();
    inv[invSize - 1].setItemID(3);
    inv[invSize - 1].setItemName("Item C");
    inv[invSize - 1].setQuantity(8);
    inv[invSize - 1].setPrice(19.99);
}

int Menu() {
    std::cout << "Enter 1 to display the inventory\n"
        "Enter 2 to search for an item\n"
        "Enter 3 to update the quantity of an item\n"
        "Enter 4 to update the price of an item\n"
        "Enter 0 to exit the program\n"
        "Enter your choice: ";
    int choice;
    cin >> choice;
    if (typeid(choice) == typeid(int) 
        && choice >= 0 && choice <= 4) {
            return choice;
    } else {
        cout << "Invalid choice:  Try again." << endl;
        return Menu();
    }
}

int main() {
    // Create a vector to store items
    std::vector<Inventory> inventory;
    // Add some items to the inventory
    initializeInventory(inventory);

    int choice = Menu();

    cout << choice << endl;

    return 0;
}
