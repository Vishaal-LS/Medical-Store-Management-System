#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class for storing product information
class Product {
public:
    string name;
    double price;
    int quantity;
    string expirationDate;
};

// Function to add a new product
void addProduct(vector<Product>& inventory) {
    Product product;
    cout << "Enter product name: ";
    cin >> product.name;
    cout << "Enter product price: ";
    cin >> product.price;
    cout << "Enter product quantity: ";
    cin >> product.quantity;
    cout << "Enter product expiration date: ";
    cin >> product.expirationDate;
    inventory.push_back(product);
    cout << "Product added successfully!" << endl;
}

// Function to display all products
void displayInventory(const vector<Product>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
    }
    else {
        cout << "Product Name\tPrice\tQuantity\tExpiration Date" << endl;
        for (const Product& product : inventory) {
            cout << product.name << "\t" << product.price << "\t"
                << product.quantity << "\t\t" << product.expirationDate << endl;
        }
    }
}

// Function to search products by name
void searchProduct(const vector<Product>& inventory, const string& name) {
    bool found = false;
    for (const Product& product : inventory) {
        if (product.name == name) {
            cout << "Product Name\tPrice\tQuantity\tExpiration Date" << endl;
            cout << product.name << "\t" << product.price << "\t"
                << product.quantity << "\t\t" << product.expirationDate << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found." << endl;
    }
}

// Function to sell a product
void sellProduct(vector<Product>& inventory) {
    string name;
    int quantity;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter quantity to sell: ";
    cin >> quantity;
    for (Product& product : inventory) {
        if (product.name == name) {
            if (product.quantity >= quantity) {
                product.quantity -= quantity;
                cout << "Product sold successfully!" << endl;
            }
            else {
                cout << "Not enough quantity in stock." << endl;
            }
            return;
        }
    }
    cout << "Product not found." << endl;
}

int main() {
    vector<Product> inventory;  // Vector to store the products in the inventory

    int choice;
    while (true) {
        cout << "Medical Store Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Sell Product" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct(inventory);
            break;
        case 2:
            displayInventory(inventory);
            break;
        case 3:
        {
            string name;
            cout << "Enter product name to search: ";
            cin >> name;
            searchProduct(inventory, name);
        }
        break;
        case 4:
            sellProduct(inventory);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
