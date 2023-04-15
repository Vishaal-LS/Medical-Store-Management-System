#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class for product information
class Product {
public:
	string name;
	double price;
	int quantity;
	string expirationdate;
};
//function to add new product to inventory.
void addProduct(vector<Product>& inventory) {
	Product product;
	cout << "Enter the Product Name: ";
	cin >> product.name;
	cout << "Enter the Product Price: ";
	cin >> product.price;
	cout << "Enter the Product Quantity: ";
	cin >> product.quantity;
	cout << "Enter the Product Expiration Date: ";
	cin >> product.expirationdate;
	inventory.push_back(product);
	std::cout << "Product added successfully!" << std::endl;
}
//function to display all products in inventory.
void displayInventory)const vector<Product>& inventory) {
	if (inventory.empty()) {
		cout << "Inventory is empty." << endl;
	}
	else {
		cout << "Product Name\tPrice\tQuantity\tExpiration Date" << endl;
		for (const Product& product : inventory) {
			cout << product.name << "/t" << product.price << ".t" << product.quantity<</t / t << product.expirationDate << endl;

		}
	}
}
//function to search products by name in inventory
void searchProduct(const vector<Product>& inventory, const string&)