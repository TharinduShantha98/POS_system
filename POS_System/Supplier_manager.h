#pragma once
#include "Supplier.h"
#include <vector>
class Supplier_manager
{
private:
	std::vector<Supplier> suppliers; // List of suppliers


public:
   
    void addSupplier(int id, const std::string& name, const std::string& contactNumber,
        const std::string& email, const std::string& address);

    void viewSuppliers() const;

    const Supplier* findSupplierById(int id) const;





};

