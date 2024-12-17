#include "customer_manager.h"


//add customer

void customer_manager::addCustomer(int id, const std::string& name, const std::string& mobileNumber) {
    customers.emplace_back(id, name, mobileNumber);  // Add customer to the list
    std::cout << "Customer added successfully!" << std::endl;
}

// View all customers
void customer_manager::viewCustomers() const {
    if (customers.empty()) {
        std::cout << "No customers found.\n";
    }
    else {
        std::cout << "--- Customer List ---\n";
        for (const auto& customer : customers) {
            customer.display();
        }
    }
}

// Update customer details
void customer_manager::updateCustomer(int id, const std::string& newMobileNumber) {
    for (auto& customer : customers) {
        if (customer.getId() == id) {
            customer.setMobileNumber(newMobileNumber);
            std::cout << "Customer updated successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Customer not found.\n";
}

//delete customer 
void customer_manager::deleteCustomer(int id) {
    auto it = std::remove_if(customers.begin(), customers.end(),
        [id](const Customer& customer) { return customer.getId() == id; });

    if (it != customers.end()) {
        customers.erase(it, customers.end()); // Remove customer from the list
        std::cout << "Customer deleted successfully!" << std::endl;
    }
    else {
        std::cout << "Customer not found.\n";
    }
}


int customer_manager::customerCount() {
    
    int id = 0;

    for (int i = 0; i < customers.size(); i++) {
        int id = customers.at(i).getId();
    
    }
    return id;



}

const Customer* customer_manager::findCustomerById(int id) const {
    for (const auto& customer : customers) {
        if (customer.getId() == id) {
            return &customer;  // Return a pointer to the customer
        }
    }
    return nullptr;  // Return nullptr if the customer is not found
}