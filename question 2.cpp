#include <iostream>
#include <string>
using namespace std;
class Product
 {
public:
    int productId;
    string productName;
    double price;
    Product(int id, const string& name, double p)
        : productId(id), productName(name), price(p) {}
    void displayProductDetails()
     {
        cout << "Product ID: " << productId << ", Name: " << productName << ", Price: $" << price << endl;
    }
};
class ShoppingCart 
{
private:
    static const int maxCapacity = 5;  
    Product products[maxCapacity];
    int size;
    double totalCost;

public:
    ShoppingCart() : size(0), totalCost(0.0) {}
    void addProduct(const Product& product) 
    {
        if (size < maxCapacity)
            {
            products[size++] = product;
            totalCost += product.price;
        }
        else
            {
            cout << "Shopping Cart is full. Cannot add more products." << endl;
        }
    }
    void displayAllProducts() 
    {
        for (int i = 0; i < size; ++i)
            {
            products[i].displayProductDetails();
        }
    }
    double calculateTotalCost() {
        return totalCost;
    }
};
class User {
public:
    int userId;
    ShoppingCart cart;
    User(int id) : userId(id) {}
    void displayUserDetails()
     {
        cout << "User ID: " << userId << endl;
    }
};
int main() 
{
   
    ShoppingCart cart;
    Product p1(1, "Product1", 10.99);
    Product p2(2, "Product2", 5.99);
    cart.addProduct(p1);
    cart.addProduct(p2);
    cout << "All Products in Cart:" << endl;
    cart.displayAllProducts();
    cout << "Total Cost: $" << cart.calculateTotalCost() << endl;
    
    User user1(101);
    user1.cart = cart;
    user1.displayUserDetails();
    cout << "User's Cart Details:" << endl;
    user1.cart.displayAllProducts();
    return 0;
}
