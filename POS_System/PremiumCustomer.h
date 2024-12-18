#pragma once
#include "BaseCustomer.h"

class PremiumCustomer : public BaseCustomer {

private:
	std::string membershipId;


public:
    PremiumCustomer(int id, const std::string& name, const std::string& membershipId)
        : BaseCustomer(id, name), membershipId(membershipId) {}

    void display() const override {
        std::cout << "Premium Customer - ID: " << id
            << ", Name: " << name
            << ", Membership ID: " << membershipId << std::endl;
    }




};