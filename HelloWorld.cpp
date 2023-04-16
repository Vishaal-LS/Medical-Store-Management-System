#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

// #0623F9 - Blue color
#define ANSI_BLUE "\033[38;2;6;35;249m"

// #F9DC06 - Yellow color
#define ANSI_YELLOW "\033[38;2;249;220;6m"

// #14CBEB - Cyan color
#define ANSI_CYAN "\033[38;2;20;203;235m"

// #EB3414 - Red color
#define ANSI_RED "\033[38;2;235;52;20m"

// #9D7662 - Brown color
#define ANSI_BROWN "\033[38;2;157;118;98m"

// #BD42B1 - Magenta color
#define ANSI_MAGENTA "\033[38;2;189;66;177m"

// #00FF58 - Green color
#define ANSI_GREEN "\033[38;2;0;255;88m"

// Reset to default color
#define ANSI_RESET "\033[0m"


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
        cout << ANSI_GREEN << "Medical Store Management System" << ANSI_RESET << endl;
        cout << "1. " << ANSI_BLUE << "Add "<< ANSI_RESET << "Product" << endl;
        cout << "2. " << ANSI_YELLOW << "Display "<< ANSI_RESET <<"Inventory"<< endl;
        cout << "3. " << ANSI_CYAN<< "Search "<< ANSI_RESET << " Product" << endl;
        cout << "4. " << ANSI_RED<< "Sell "<< ANSI_RESET <<"Product" << endl;
        cout << "5. " << ANSI_BROWN<< "Exit" <<ANSI_RESET<< endl;

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
//-LSV
