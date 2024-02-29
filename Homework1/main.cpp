// Copyright Max Dupler 2024
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

bool searchID(std::vector<Inventory>& inv, int id, Inventory& item) {
    for (Inventory i : inv) {
        if (i.getItemID() == id) {
            item = i;
            return true;
        }
    }
    return false;
}

void displayInventory(std::vector<Inventory>& inv) {
    for (Inventory i : inv) {
        i.displayItemDetails();
        cout << "---------------------------" << endl;
    }
}

void searchItem(std::vector<Inventory>& inv) {
    int id;
    cout << "Enter the item ID to search for: ";
    cin >> id;
    Inventory i;
    if (searchID(inv, id, i)) {
        cout << "Item found! Details:" << endl;
        i.displayItemDetails();
    }
    
    cout << "Item " << id <<  " not found in the inventory." << endl;
}

void updateQuantity(std::vector<Inventory>& inv) {
    int id;
    cout << "Enter item ID to update quantity: ";
    cin >> id;
    Inventory i;
    if (searchID(inv, id, i)) {
        cout << "Current quantity is " << i.getQuantity() << endl;
        cout << "Enter new quantity: ";
        int newQty;
        cin >> newQty;
        i.setQuantity(newQty);
        cout << "Quantity is now " << i.getQuantity() << endl;
        return;
    }
    cout << "Invalid item ID.  Exiting program." << endl;

}

void updatePrice(std::vector<Inventory>& inv) {
    int id;
    cout << "Enter item ID to update price: ";
    cin >> id;
    Inventory i;
    if (searchID(inv, id, i)) {
        cout << "Current price is " << i.getPrice();
        cout << "Enter new price: ";
        int newPrice;
        cin >> newPrice;
        i.setPrice(newPrice);
        cout << "Price is now " << i.getPrice();
        return;
    }
    cout << "Invalid item ID.  Exiting program." << endl;
}

void Menu(std::vector<Inventory>& inv) {
    std::cout << "Enter 1 to display the inventory\n"
        "Enter 2 to search for an item\n"
        "Enter 3 to update the quantity of an item\n"
        "Enter 4 to update the price of an item\n"
        "Enter 0 to exit the program\n"
        "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            displayInventory(inv);
            break;
        case 2:
            searchItem(inv);
            exit(0);
        case 3:
            updateQuantity(inv);
            break;
        case 4:
            updatePrice(inv);
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice:  Try again." << endl;
            break;
    }
}

int main() {
    // Create a vector to store items
    std::vector<Inventory> inventory;
    // Add some items to the inventory
    initializeInventory(inventory);

    while (true) {
        Menu(inventory);
    }

    return 0;
}
