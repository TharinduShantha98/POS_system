#pragma once
#include <string>
#include <iostream>


class Supplier{

private:
    int id;                  // Unique ID for the supplier
    std::string name;        // Supplier name
    std::string contactNumber; // Contact number
    std::string email;       // Email address
    std::string address;     // Supplier address


public:
    // Constructor
    Supplier(int id, const std::string& name, const std::string& contactNumber,
        const std::string& email, const std::string& address);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getContactNumber() const;
    std::string getEmail() const;
    std::string getAddress() const;

    // Setters
    void setContactNumber(const std::string& newContactNumber);
    void setEmail(const std::string& newEmail);
    void setAddress(const std::string& newAddress);

    // Display supplier details
    void display() const;


};

