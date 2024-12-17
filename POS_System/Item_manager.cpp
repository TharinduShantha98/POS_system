#include "Item_manager.h"
#include <iostream>

void Item_manager::addItem(int id, const std::string& name, double price, int stockQuantity) {
    items.emplace_back(id, name, price, stockQuantity);
    std::cout << "Item added successfully!\n" << std::endl;
}



void Item_manager::viewItems() const {
    if (items.empty()) {
        std::cout << "No items in the inventory.\n" << std::endl;
    }
    else {
        std::cout << "--- Item List ---" << std::endl;
        for (const auto& item : items) {
            item.display();
        }
        std::cout << std::endl;
    }
}

void Item_manager::updateItem(int id, const std::string& newName, double newPrice, int newStockQuantity) {
    auto it = std::find_if(items.begin(), items.end(),
        [id](const Item& item) { return item.getId() == id; });

    if (it != items.end()) {
        it->setName(newName);
        it->setPrice(newPrice);
        it->setStockQuantity(newStockQuantity);
        std::cout << "Item updated successfully!\n" << std::endl;
    }
    else {
        std::cout << "Item not found.\n" << std::endl;
    }
}

void Item_manager::deleteItem(int id) {
    auto it = std::remove_if(items.begin(), items.end(),
        [id](const Item& item) { return item.getId() == id; });

    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << "Item deleted successfully!\n" << std::endl;
    }
    else {
        std::cout << "Item not found.\n" << std::endl;
    }
}

// Reduce stock for an item (used during order placement)
bool Item_manager::reduceItemStock(int id, int quantity) {
    auto it = std::find_if(items.begin(), items.end(),
        [id](const Item& item) { return item.getId() == id; });

    if (it != items.end()) {
        if (quantity <= it->getStockQuantity()) {
            it->reduceStock(quantity);
            std::cout << "Stock reduced successfully!\n" << std::endl;
            return true;
        }
        else {
            std::cout << "Insufficient stock for the requested quantity.\n" << std::endl;
        }
    }
    else {
        std::cout << "Item not found.\n" << std::endl;
    }
    return false;
}

// Restock an item
void Item_manager::restockItem(int id, int quantity) {
    auto it = std::find_if(items.begin(), items.end(),
        [id](const Item& item) { return item.getId() == id; });

    if (it != items.end()) {
        it->addStock(quantity);
        std::cout << "Item restocked successfully!\n" << std::endl;
    }
    else {
        std::cout << "Item not found.\n" << std::endl;
    }
}



