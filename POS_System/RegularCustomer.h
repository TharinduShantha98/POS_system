#pragma once
#include "BaseCustomer.h"



class RegularCustomer : public BaseCustomer{


private:
	std::string mobileNumber;

public:
    RegularCustomer(int id, const std::string& name, const std::string& mobileNumber)
        : BaseCustomer(id, name), mobileNumber(mobileNumber) {}

    void display() const override {
        std::cout << "Regular Customer - ID: " << id
            << ", Name: " << name
            << ", Mobile Number: " << mobileNumber << std::endl;
    }


};