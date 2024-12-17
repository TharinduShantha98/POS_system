#include <iostream>
#include <string>
#include "item_manager.h"
#include "customer_manager.h"
#include "Supplier_manager.h"
#include "Place_order.h"


void displayMainDashboard() {
    
    std::cout << "===================================" << std::endl;
    std::cout << "      Simple POS System Dashboard  " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. Manage Items" << std::endl;
    std::cout << "2. Manage Customers" << std::endl;
    std::cout << "3. Manage Supplier" << std::endl;
    std::cout << "4. Place Order" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "Enter your choice: ";
}

void displayItemMenu() {
    
    std::cout << "\n--- Manage Items ---" << std::endl;
    std::cout << "1. Add Item" << std::endl;
    std::cout << "2. View Items" << std::endl;
    std::cout << "3. Update Items" << std::endl;
    std::cout << "4. Delete Items" << std::endl;
    std::cout << "5. Go Back to Dashboard" << std::endl;
    std::cout << "Enter your choice: ";
}


void addItem(Item_manager& itemManager,Supplier_manager& supplierManager) {
    int id;
    std::string name;
    double price;
    int qty;
    int supplierId;

    std::cout << "Enter Item ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Item Name: ";
    std::cin >> name;
    std::cin.ignore();
    std::cout << "Enter Item Price: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter Qty: ";
    std::cin >> qty;
    std::cin.ignore();
    std::cout << "Enter supplierId: ";
    std::cin >> supplierId;
    std::cin.ignore();


    const Supplier* supplier  = supplierManager.findSupplierById(supplierId);
    if (supplier) {
        itemManager.addItem(id, name, price, qty, supplierId);
    }
    else {
        std::cout << "Your supplier id is wrong !!! ";
        supplierManager.viewSuppliers();

    }

    

}



void viewItems(const Item_manager& itemManager){
    itemManager.viewItems();
    
}


void updateItems(Item_manager& itemManager) {
   

    int id;
    std::string newName;
    double newPrice;
    int qty;

    std::cout << "Enter Item ID to Update: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter New Name: ";
    std::getline(std::cin, newName);
    std::cout << "Enter New Price: ";
    std::cin >> newPrice;
    std::cout << "Enter Qty: ";
    std::cin >> qty;
    itemManager.updateItem(id, newName, newPrice, qty);
 

}


void deleteItems(Item_manager& itemManager) {

    int id;
    std::cout << "Enter Item ID to Delete: ";
    std::cin >> id;
    itemManager.deleteItem(id);


}


void manageItems(Item_manager& itemManager,Supplier_manager& supplierManager) {
    
    int itemChoice;
    bool managingItems = true;
    
    while (managingItems) {
        displayItemMenu();
        std::cin >> itemChoice;

        switch (itemChoice) {
        case 1:
            system("CLS");
            addItem(itemManager, supplierManager);
            break;
        case 2:
            system("CLS");   
            viewItems(itemManager);
            break;
        case 3:
            system("CLS");
            viewItems(itemManager);
            updateItems(itemManager);
            break;
        case 4:
            system("CLS");
            viewItems(itemManager);
            deleteItems(itemManager);
            break;
        case 5:
            managingItems = false;
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }
}



void dispalyCustomerMenu() {

    std::cout << "\n--- customer Manage ---" << std::endl;
    std::cout << "1. Add customer" << std::endl;
    std::cout << "2. View customer" << std::endl;
    std::cout << "3. Update customer" << std::endl;
    std::cout << "4. Delete customer" << std::endl;
    std::cout << "5. Go Back to Dashboard" << std::endl;
    std::cout << "Enter your choice: ";

}


void addCustomer(customer_manager& customerManager) {

    int id;
    std::string customerName;
    std::string mobileNumber;

    std::cout << "Enter customer name: ";
    std::cin >> customerName;
    std::cin.ignore();
    std::cout << "Enter mobileNumber: ";
    std::cin >> mobileNumber;
    
  
    int customerCount  =  customerManager.customerCount();
    customerCount = customerCount + 1;
    customerManager.addCustomer(customerCount, customerName,mobileNumber);


}


void viewCustomer(const customer_manager& customerManager) {
    customerManager.viewCustomers();

}

void updateCustomer(customer_manager& customerManager) {

    int id;
    std::string mobileNumber;
    std::cout << "Enter Customer ID to update: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter new mobile number: ";
    std::getline(std::cin, mobileNumber);
    customerManager.updateCustomer(id, mobileNumber);

}
void deleteCustomer(customer_manager& customerManager) {

    int id;
    std::cout << "Enter Customer ID to delete: ";
    std::cin >> id;
    customerManager.deleteCustomer(id);
}






void customerManage(customer_manager& customerManager) {

    int customerChoise;
    bool customerManage = true;
    //Adding sample customers

    while (customerManage) {
        dispalyCustomerMenu();
        std::cin >> customerChoise;

        switch (customerChoise) {
        case 1:
            system("CLS");
            addCustomer(customerManager);
            break;
        case 2:
            system("CLS");
            viewCustomer(customerManager);
            break;
        case 3:
            system("CLS");
            updateCustomer(customerManager);
            break;
        case 4:
            customerManage = false;
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }



}



void dispalySupplierMenu() {
    std::cout << "\n--- Supplier Manage ---" << std::endl;
    std::cout << "1. Add Supplier" << std::endl;
    std::cout << "2. View Supplier" << std::endl;
    std::cout << "3. find by Supplier Id" << std::endl;
    std::cout << "4. Go Back to Dashboard" << std::endl;
    std::cout << "Enter your choice: ";
}

void handleAddSupplier(Supplier_manager& supplierManager) {
    int id;
    std::string name, contactNumber, email, address;

    std::cout << "Enter Supplier ID: ";
    std::cin >> id;
    std::cin.ignore(); 

    std::cout << "Enter Supplier Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Contact Number: ";
    std::getline(std::cin, contactNumber);

    std::cout << "Enter Email Address: ";
    std::getline(std::cin, email);

    std::cout << "Enter Address: ";
    std::getline(std::cin, address);

    supplierManager.addSupplier(id, name, contactNumber, email, address);
    std::cout << "Supplier added successfully!" << std::endl;
}

void handleViewSuppliers(const Supplier_manager& supplierManager) {
    supplierManager.viewSuppliers();
}

void handleFindSupplierById(const Supplier_manager& supplierManager) {
    int id;
    std::cout << "Enter Supplier ID to search: ";
    std::cin >> id;

    const Supplier* supplier = supplierManager.findSupplierById(id);
    if (supplier) {
        std::cout << "Supplier Found:\n";
        supplier->display();
    }
    else {
        std::cout << "Supplier with ID " << id << " not found.\n";
    }
}

void supplierManagers(Supplier_manager& supplierManager) {

    int supplierChose;
    bool supplierManger = true;

    while (supplierManger) {
        dispalySupplierMenu();
        std::cin >> supplierChose;

        switch (supplierChose) {
        case 1:
            system("CLS");
            handleAddSupplier(supplierManager);
            break;
        case 2:
            system("CLS");
            handleViewSuppliers(supplierManager);
            break;
        case 3:
            system("CLS");
            handleFindSupplierById(supplierManager);
            break;
        case 4:
            system("CLS");
            supplierManger = false;
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }
}


void dispalyPlaceOrder() {
    std::cout << "\n--- Place Order Manage ---" << std::endl;
    std::cout << "1. place order" << std::endl;
    std::cout << "2. Go Back to Dashboard" << std::endl;
    std::cout << "Enter your choice: ";
}



void setPlaceOrder(Place_order& place_order,customer_manager& customerManager, Item_manager& itemManager) {
    place_order.placeOrder(customerManager, itemManager);

}



void place_order(Place_order& placeOrder, customer_manager& customerManager, Item_manager& itemManager) {

    int placeOrderChoise;
    bool placeOrderMange = true;


    while (placeOrderMange) {
        dispalyPlaceOrder();
        std::cin >> placeOrderChoise;

        switch (placeOrderMange){
        case   1:
            setPlaceOrder(placeOrder, customerManager, itemManager);
            break;

        default:
            break;
        }

    }


}




int main()
{
    Item_manager itemManager;
    customer_manager customerManager;
    Supplier_manager supplierManager;
    Place_order placeOrder;

   

    int itemChoice;
    bool running  = true;


    while (running) {
        displayMainDashboard();
        std::cin >> itemChoice;

        switch (itemChoice) {
        case 1:
            system("CLS");
            manageItems(itemManager,supplierManager);
            break;
        case 2:
            system("CLS");
            customerManage(customerManager);
            break;
        case 3:
            system("CLS");
            supplierManagers(supplierManager);
            break;
        case 4:
            system("CLS");

            supplierManager.addSupplier(1, "lamal", "0769773032", 
                "a@gmail.com", "qwer");
            itemManager.addItem(1, "Kamal", 12, 120, 1);
            customerManager.addCustomer(1, "Tharindu", "0786667878");

            place_order(placeOrder, customerManager, itemManager);
            break;
        case 5:
            std::cout << "Exiting... Thank you!" << std::endl;
            running = false;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }
    return 0;



}

