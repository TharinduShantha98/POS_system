#pragma once
#include <string>
#include <iostream>

class BaseCustomer {

protected:
	int id;
	std::string name;

public:

    BaseCustomer(int id, const std::string& name) : id(id), name(name) {}

    virtual ~BaseCustomer() {}

    virtual void display() const = 0; // Pure virtual function

    int getId() const { return id; }

    std::string getName() const { return name; }




};