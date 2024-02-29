// Copyright 2024 Max Dupler

#include "Inventory.h" 
#include <iostream>    
#include <string>       

using std::cout;       
using std::endl;       

// Default constructor for the Inventory class
Inventory::Inventory() {
    itemID = -1;        
    itemName = "";      
    price = 0.0;        
    quantity = 0;       
}

// Parameterized constructor for the Inventory class
Inventory::Inventory(int id, const std::string& name, int qty, double itemPrice) {
    this->itemID = id;          
    this->itemName = name;      
    this->quantity = qty;       
    this->price = itemPrice;    
}

// Getter function for itemID
int Inventory::getItemID() const {
    return this->itemID;        
}

// Setter function for itemID
void Inventory::setItemID(int id) {
    this->itemID = id;          
}

// Getter function for itemName
const std::string& Inventory::getItemName() const {
    return this->itemName;      
}

// Setter function for itemName
void Inventory::setItemName(const std::string& name) {
    this->itemName = name;      
}

// Getter function for quantity
int Inventory::getQuantity() const {
    return this->quantity;      
}

// Setter function for quantity
void Inventory::setQuantity(int qty) {
    this->quantity = qty;       
}

// Getter function for price
double Inventory::getPrice() const {
    return this->price;         
}

// Setter function for price
void Inventory::setPrice(double itemPrice) {
    this->price = itemPrice;    
}

// Display item details
void Inventory::displayItemDetails() const {
    cout << "Item ID: " << this->itemID << endl;        
    cout << "Item Name: " << this->itemName << endl;    
    cout << "Quantity: " << this->quantity << endl;     
    cout << "Price: $" << this->price << endl;          
}
