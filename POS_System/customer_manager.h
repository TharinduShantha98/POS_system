#pragma once

#include "customer.h"
#include <vector>


class customer_manager
{
private:
    std::vector<Customer> customers; // Store customers
public:
   
    void addCustomer(int id, const std::string& name, const std::string& mobileNumber);
 
    void viewCustomers() const;
  
    void updateCustomer(int id, const std::string& newMobileNumber);

    void deleteCustomer(int id);

    int customerCount();

    const Customer* findCustomerById(int id) const;
};









