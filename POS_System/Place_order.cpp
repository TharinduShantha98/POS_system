#include "Place_order.h"


void Place_order::placeOrder(CustomerManager& customerManager, Item_manager& itemManager) {
    int customerId;
    std::cout << "Enter Customer ID to place an order: ";
    std::cin >> customerId;

    // Find customer by ID
    const BaseCustomer* customer = customerManager.findCustomerById(customerId);
    if (!customer) {
        std::cout << "Customer not found. Please try again.\n";
        return;
    }

    // Create a new order for the customer
    static int orderId = 1;  // Static to simulate order ID increment
    Order order(orderId++, customerId);

    int itemChoice;
    bool addingItems = true;

    while (addingItems) {
        // Display available items
        itemManager.viewItems();
        std::cout << "Enter Item ID to add to the order (0 to finish): ";
        std::cin >> itemChoice;

        if (itemChoice == 0) {
            addingItems = false;
        }
        else {
            int quantity;
            const Item* item = itemManager.findItemById(itemChoice);
            if (item) {
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                order.addItemToOrder(*item, quantity);  // Add item to the order
            }
            else {
                std::cout << "Item not found. Please try again.\n";
            }
        }
    }

    // Display order details
    order.getOrderDetails();

    // Confirm payment
    char paymentChoice;
    std::cout << "Do you want to complete the order and mark as paid? (y/n): ";
    std::cin >> paymentChoice;

    if (paymentChoice == 'y' || paymentChoice == 'Y') {
        order.markAsPaid();
        // Reduce stock for items in the order
        for (const auto& item : order.getOrderedItems()) {
            itemManager.reduceItemStock(item.getId(), 1);  // Reduce stock by 1 for each item in the order
        }
    }
}
