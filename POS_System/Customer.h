#pragma once
#include <string>
#include <iostream>


class Customer
{

private:
    int id;
    std::string name;
    std::string mobileNumber; // Replaced email with mobileNumber



public:
    // Constructor
    Customer(int id, const std::string& name, const std::string& mobileNumber);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getMobileNumber() const;

    // Setters
    void setName(const std::string& newName);
    void setMobileNumber(const std::string& newMobileNumber);

    // Display customer details
    void display() const;
};






