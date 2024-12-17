#pragma once
#include <string>
#include <iostream>



class Item{

private:
    int id;
    std::string name;
    double price;
    int stockQuantity;


public:
    
    Item(int id, const std::string& name, double price, int stockQuantity);

    int getId() const;

    std::string getName() const;

    double getPrice() const;

    int getStockQuantity() const;

    void setName(const std::string& newName);

    void setPrice(double newPrice);

    void setStockQuantity(int newStockQuantity);

    void display() const;
    
    void addStock(int quantity);

    void reduceStock(int quantity);

};

