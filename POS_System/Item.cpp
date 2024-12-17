#include "Item.h"

Item::Item(int id, const std::string& name, double price, int stockQuantity, int supplierId)
    : id(id), name(name), price(price), stockQuantity(stockQuantity), supplierId(supplierId){}


int Item::getId() const {
    return id;
}

std::string Item::getName() const {
    return name;
}

double Item::getPrice() const {
    return price;
}

int Item::getStockQuantity() const { return stockQuantity; }

void Item::setStockQuantity(int newStockQuantity) { stockQuantity = newStockQuantity; }



void Item::setName(const std::string& newName) {
    name = newName;
}
void Item::setPrice(double newPrice) {
    price = newPrice;
}

void Item::addStock(int quantity) { stockQuantity += quantity; }

void Item::reduceStock(int quantity) {
    if (quantity <= stockQuantity)
        stockQuantity -= quantity;
    else
        std::cout << "Insufficient stock to reduce!" << std::endl;
}

void Item::display() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Price: $" << price
        << ", Qty :" << stockQuantity
        << std::endl;
}


void Item::setSupplierId(int supplier_id) {
    supplierId = supplier_id;
}

int Item::getSupplierId(int itemCode) {
    return supplierId;
}