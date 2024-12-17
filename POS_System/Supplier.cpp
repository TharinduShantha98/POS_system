#include "Supplier.h"



// Constructor
Supplier::Supplier(int id, const std::string& name, const std::string& contactNumber,
    const std::string& email, const std::string& address)
    : id(id), name(name), contactNumber(contactNumber), email(email), address(address) {}

// Getters
int Supplier::getId() const { return id; }
std::string Supplier::getName() const { return name; }
std::string Supplier::getContactNumber() const { return contactNumber; }
std::string Supplier::getEmail() const { return email; }
std::string Supplier::getAddress() const { return address; }

// Setters
void Supplier::setContactNumber(const std::string& newContactNumber) { contactNumber = newContactNumber; }
void Supplier::setEmail(const std::string& newEmail) { email = newEmail; }
void Supplier::setAddress(const std::string& newAddress) { address = newAddress; }

// Display supplier details
void Supplier::display() const {
    std::cout << "Supplier ID: " << id
        << ", Name: " << name
        << ", Contact: " << contactNumber
        << ", Email: " << email
        << ", Address: " << address
        << std::endl;
}


