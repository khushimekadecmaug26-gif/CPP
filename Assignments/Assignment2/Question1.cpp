#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Product class
class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:

    // Function to accept product details
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // Function to display product details
    void displayDetails() const {
        cout << setw(10) << productId;
        cout << setw(15) << name;
        cout << setw(12) << fixed << setprecision(2) << price;
        cout << setw(10) << quantity;
        cout << setw(15) << totalValue();
    }

    // Function to calculate total value
    double totalValue() const {
        return price * quantity;
    }

    // Function to check low stock
    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    // Function to get product name
    string getName() const {
        return name;
    }
};


// Function Overloading - 1
double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

// Function Overloading - 2
double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

// Function Overloading - 3
double reorderCost(int qty, double unitPrice, double taxRate) {
    double cost = qty * unitPrice;

    double tax = cost * taxRate / 100;

    return cost + tax;
}

// Function with default argument
double applyDiscount(double price, double discountPercent = 10.0) {
    double discount = price * discountPercent / 100;

    return price - discount;
}


int main() {

    Product products[5];

    cout << "===== ENTER PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << endl;

        products[i].acceptDetails();
    }


    cout << "\n\n===== INVENTORY REPORT =====" << endl;

    cout << setw(10) << "ID";
    cout << setw(15) << "Name";
    cout << setw(12) << "Price";
    cout << setw(10) << "Qty";
    cout << setw(15) << "Total Value";

    cout << endl;

    for (int i = 0; i < 5; i++) {
        products[i].displayDetails();
        cout << endl;
    }


    int highestIndex = 0;

    for (int i = 1; i < 5; i++) {

        if (products[i].totalValue() >
            products[highestIndex].totalValue()) {

            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product : "
         << products[highestIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << products[highestIndex].totalValue()
         << ")" << endl;


    int threshold;

    cout << "\nEnter stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock (threshold: "
         << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < 5; i++) {

        if (products[i].isLowStock(threshold)) {

            cout << products[i].getName() << " ";

            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }

    cout << endl;

    cout << "\n===== REORDER COST =====" << endl;

    cout << "Integer quantity cost: "
         << reorderCost(10, 50.0)
         << endl;

    cout << "Fractional quantity cost: "
         << reorderCost(10.5, 50.0)
         << endl;

    cout << "Cost with tax: "
         << reorderCost(10, 50.0, 18.0)
         << endl;


    cout << "\n===== DISCOUNT =====" << endl;

    
    cout << "Price after default 10% discount: "
         << applyDiscount(1000)
         << endl;

    
    cout << "Price after 20% discount: "
         << applyDiscount(1000, 20)
         << endl;


    return 0;
}