#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Customer.h"



class Order{


private:
    int orderId;
    int customerId;
    std::vector<Item> orderedItems;  // Items in the order
    double totalAmount;
    bool isPaid;


public:
    // Constructor
    Order(int orderId, int customerId);

    // Add item to order
    void addItemToOrder(const Item& item, int quantity);

    // Get order details
    void getOrderDetails() const;

    // Calculate total amount
    double calculateTotal() const;

    // Mark order as paid
    void markAsPaid();

    // Display order details
    void displayOrder() const;

    const std::vector<Item>& getOrderedItems() const;

};

