#include "Customer.h"


Customer::Customer(int id, const std::string& name, const std::string& mobileNumber)
    : id(id), name(name), mobileNumber(mobileNumber) {}

// Getters
int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getMobileNumber() const {
    return mobileNumber;
}

// Setters
void Customer::setName(const std::string& newName) {
    name = newName;
}

void Customer::setMobileNumber(const std::string& newMobileNumber) {
    mobileNumber = newMobileNumber;
}

// Display customer details
void Customer::display() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Mobile Number: " << mobileNumber
        << std::endl;
}