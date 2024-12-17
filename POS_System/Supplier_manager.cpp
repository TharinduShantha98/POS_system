#include "Supplier_manager.h"

void Supplier_manager::addSupplier(int id, const std::string& name, const std::string& contactNumber,
    const std::string& email, const std::string& address) {
    suppliers.emplace_back(id, name, contactNumber, email, address);
}


// View all suppliers
void Supplier_manager::viewSuppliers() const {
    if (suppliers.empty()) {
        std::cout << "No suppliers available.\n";
    }
    else {
        std::cout << "--------------------------------------------------- Supplier List -------------------------------------------------- \n";
        for (const auto& supplier : suppliers) {
            supplier.display();
        }
    }
}

const Supplier* Supplier_manager::findSupplierById(int id) const {
    for (const auto& supplier : suppliers) {
        if (supplier.getId() == id) {
            return &supplier;
        }
    }
    return nullptr; // Return null if not found
}





