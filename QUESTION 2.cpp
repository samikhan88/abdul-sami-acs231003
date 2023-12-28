#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string productId;
    string productName;
    double price;

public:
    Product(string id, string name, double cost) : productId(id), productName(name), price(cost) {}

    void displayDetails() {
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
    }
};

class ShoppingCart {
private:
    Product** products;
    int numProducts;

public:
    ShoppingCart() : products(nullptr), numProducts(0) {}

    void addProduct(Product* product) {
        Product** newProducts = new Product*[numProducts + 1];
        for (int i = 0; i < numProducts; i++) {
            newProducts[i] = products[i];
        }
        newProducts[numProducts] = product;
        delete[] products;
        products = newProducts;
        numProducts++;
    }

    void displayAllProducts() {
        for (int i = 0; i < numProducts; i++) {
            products[i]->displayDetails();
            cout << endl;
        }
    }

    double calculateTotalCost() {
        double totalCost = 0;
        for (int i = 0; i < numProducts; i++) {
            totalCost += products[i]->getPrice();
        }
        return totalCost;
    }
};

class User {
private:
    string userId;
    ShoppingCart* cart;

public:
    User(string id) : userId(id), cart(nullptr) {}

    void setShoppingCart(ShoppingCart* shoppingCart) {
        cart = shoppingCart;
    }

    void displayUserDetails() {
        cout << "User ID: " << userId << endl;
        if (cart != nullptr) {
            cout << "User has a shopping cart" << endl;
        } else {
            cout << "User does not have a shopping cart" << endl;
        }
    }
};

int main() {
    // Create products
    Product* product1 = new Product("P001", "Product 1", 10.99);
    Product* product2 = new Product("P002", "Product 2", 5.99);
    Product* product3 = new Product("P003", "Product 3", 15.99);

    // Create shopping cart
    ShoppingCart* cart = new ShoppingCart();

    // Add products to the cart
    cart->addProduct(product1);
    cart->addProduct(product2);
    cart->addProduct(product3);

    // Create user
    User* user = new User("U001");

    // Associate shopping cart with user
    user->setShoppingCart(cart);

    // Display user details
    user->displayUserDetails();

    // Display all products in the cart
    cart->displayAllProducts();

    // Calculate total cost
    double totalCost = cart->calculateTotalCost();
    cout << "Total Cost: $" << totalCost << endl;

    // Clean up memory
    delete product1;
    delete product2;
    delete product3;
    delete cart;
    delete user;

    return 0;
}
