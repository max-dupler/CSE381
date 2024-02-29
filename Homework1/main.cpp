// Copyright Max Dupler 2024

#include "Inventory.h" 
#include <string>       
#include <iostream>     
#include <vector>       
#include <iomanip>      

using std::cout;        
using std::string;      
using std::cin;         
using std::endl;        
using std::vector;      

// Function to create initial inventory items
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

// Function to search for an item by ID
bool searchID(std::vector<Inventory>& inv, int id, Inventory& item) {
    for (Inventory i : inv) {
        if (i.getItemID() == id) {
            item = i;
            return true;
        }
    }
    return false;
}

// Function to display inventory details
void displayInventory(std::vector<Inventory>& inv) {
    for (Inventory i : inv) {
        i.displayItemDetails();
        cout << "---------------------------" << endl;
    }
}

// Function to search for an item by ID and display details
void searchItem(std::vector<Inventory>& inv) {
    int id;
    cout << "Enter the item ID to search for: " << endl;
    cin >> id;
    Inventory i;
    if (searchID(inv, id, i)) {
        cout << "Item found! Details:" << endl;
        i.displayItemDetails();
    } else {
        cout << "Item " << id <<  " not found in the inventory." << endl;
    }
    cout << endl;
}

// Function to update the quantity of an item
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
        for (size_t i = 0; i < inv.size(); ++i) {
            if (inv[i].getItemID() == id) {
                inv[i].setQuantity(newQty);
                break;
            }
        }
        cout << "Quantity is now " << i.getQuantity() << endl << endl;
        return;
    } else {
        cout << "\nInvalid item ID.  Exiting program.\n" << endl;
        exit(0);
    }
}

// Function to update the price of an item
void updatePrice(std::vector<Inventory>& inv) {
    int id;
    cout << "Enter item ID to update price: ";
    cin >> id;
    Inventory i;
    if (searchID(inv, id, i)) {
        cout << "Current price is " << i.getPrice() << endl;
        cout << "Enter new price: ";
        double newPrice;
        cin >> newPrice;
        i.setPrice(newPrice);
        for (size_t i = 0; i < inv.size(); ++i) {
            if (inv[i].getItemID() == id) {
                inv[i].setPrice(newPrice);
                break;
            }
        }
        cout << "Price is now " << i.getPrice() << endl << endl;
        return;
    }
    cout << "\nInvalid item ID.  Exiting program.\n" << endl;
    exit(0);
}

// Function to display the menu options
void displayMenu() {
     std::cout << "Enter 1 to display the inventory\n"
        "Enter 2 to search for an item\n"
        "Enter 3 to update the quantity of an item\n"
        "Enter 4 to update the price of an item\n"
        "Enter 0 to exit the program\n"
        "Enter your choice: ";
}

// Function to handle user input and execute corresponding actions
void Menu(std::vector<Inventory>& inv) {
    displayMenu();

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            displayInventory(inv);
            break;
        case 2:
            searchItem(inv);
            break;
        case 3:
            updateQuantity(inv);
            break;
        case 4:
            updatePrice(inv);
            break;
        case 0:
            exit(0);
        default:
            cout << endl << "Invalid choice:  Try again.\n" << endl;
            break;
    }
}

// Main function
int main() {
    // Create a vector to store items
    std::vector<Inventory> inventory;
    // Add some items to the inventory
    initializeInventory(inventory);

    // Continuously display the menu and handle user input
    while (true) {
        Menu(inventory);
    }

    return 0;
}
