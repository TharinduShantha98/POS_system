#pragma once

#include "BaseCustomer.h"
#include "RegularCustomer.h"
#include "PremiumCustomer.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>


class CustomerManager {

private:
    static int totalCustomers; 

    std::vector<std::unique_ptr<BaseCustomer>> customers; // Smart pointers for memory management
   


public:
    CustomerManager() = default;

    // Add customer
    void addRegularCustomer(int id, const std::string& name, const std::string& mobileNumber) {
        customers.push_back(std::make_unique<RegularCustomer>(id, name, mobileNumber));
        totalCustomers++;
    }

    void addPremiumCustomer(int id, const std::string& name, const std::string& membershipId) {
        customers.push_back(std::make_unique<PremiumCustomer>(id, name, membershipId));
        totalCustomers++;
    }

    // View all customers
    void viewCustomers() const {
        if (customers.empty()) {
            std::cout << "No customers found.\n";
        }
        else {
            for (const auto& customer : customers) {
                customer->display();
            }
        }
    }

    // Find customer by ID
    const BaseCustomer* findCustomerById(int id) const {
        for (const auto& customer : customers) {
            if (customer->getId() == id) {
                return customer.get();
            }
        }
        throw std::runtime_error("Customer not found!");
    }

    // Delete customer
    void deleteCustomer(int id) {
        auto it = std::remove_if(customers.begin(), customers.end(),
            [id](const std::unique_ptr<BaseCustomer>& customer) {
                return customer->getId() == id;
            });

        if (it != customers.end()) {
            customers.erase(it, customers.end());
            totalCustomers--;
            std::cout << "Customer deleted successfully.\n";
        }
        else {
            std::cout << "Customer not found.\n";
        }
    }

    // Get total customer count
    static int getTotalCustomers() {
        return totalCustomers;
    }


};

