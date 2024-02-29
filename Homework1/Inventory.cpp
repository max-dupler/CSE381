// Copyright 2024 Max Dupler
#include "Inventory.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;


Inventory::Inventory() {
    itemID = -1;
    itemName = "";
    price = 0.0;
    quantity = 0;
}
Inventory::Inventory(int id, const std::string& name,
    int qty, double itemPrice) {
    this->itemID = id;
    this->itemName = name;
    this->quantity = qty;
    this->price = itemPrice;
}

// Getter and setter functions
int Inventory::getItemID() const {
    return this->itemID;
}
void Inventory::setItemID(int id) {
    this->itemID = id;
}

const std::string& Inventory::getItemName() const {
    return this->itemName;
}

void Inventory::setItemName(const std::string& name) {
    this->itemName = name;
}

int Inventory::getQuantity() const {
    return this->quantity;
}
void Inventory::setQuantity(int qty) {
    this->quantity = qty;
}

double Inventory::getPrice() const {
    return this->price;
}
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
