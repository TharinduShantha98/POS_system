#pragma once

#include "item.h"
#include <vector>
#include <algorithm>


class Item_manager{

private:
	std::vector<Item> items;


public:
    void addItem(int id, const std::string& name, double price,int stockQuantity);
    void viewItems() const;
    void updateItem(int id, const std::string& newName, double newPrice, int stockQuantity);
    void deleteItem(int id);
    bool reduceItemStock(int id, int quantity); // For order processing
    void restockItem(int id, int quantity);    // Restock an item


};

