#include "Order.h"
#include <iostream>

Order::Order(int orderId, int customerId) : orderId(orderId), customerId(customerId), totalAmount(0), isPaid(false) {}

// Add item to the order
void Order::addItemToOrder(const Item& item, int quantity) {
    for (int i = 0; i < quantity; ++i) {
        orderedItems.push_back(item);
    }
}

double Order::calculateTotal() const {
    double total = 0;
    for (const auto& item : orderedItems) {
        total += item.getPrice(); // Accumulate the price of each item
    }
    return total; // Return the calculated total without modifying the object
}

void Order::getOrderDetails() const {
    std::cout << "Order ID: " << orderId << "\nCustomer ID: " << customerId << "\nItems:\n";
    for (const auto& item : orderedItems) {
        std::cout << "- " << item.getName() << " (Price: $" << item.getPrice() << ", Quantity: " << 1 << ")\n";
    }
    std::cout << "Total Amount: $" << calculateTotal() << "\n";
}



void Order::markAsPaid() {
    isPaid = true;
    std::cout << "Payment received. Order completed!" << std::endl;
}

// Display the order details
void Order::displayOrder() const {
    std::cout << "Order ID: " << orderId << ", Total: $" << calculateTotal() << "\n";
    std::cout << "Order Status: " << (isPaid ? "Paid" : "Pending") << "\n";
}

const std::vector<Item>& Order::getOrderedItems() const {
    return orderedItems;
}