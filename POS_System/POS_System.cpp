#include <iostream>
#include <string>
#include "item_manager.h"
#include "customer_manager.h"
#include "Supplier_manager.h"
#include "Place_order.h"
#include "CustomerManager.h"
#include <limits>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

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
    std::cout << "===================================" << std::endl;
    std::cout << "           Manage Items           " << std::endl;
    std::cout << "===================================" << std::endl;
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
        system("CLS");
        std::cout << "Your supplier id is wrong !!! \n";
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
            system("CLS");
            managingItems = false;
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }
}



void dispalyCustomerMenu() {
    std::cout << "===================================" << std::endl;
    std::cout << "          customer Manage          " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. Add Regular Customer\n";
    std::cout << "2. Add Premium Customer\n";
    std::cout << "3. View All Customers\n";
    std::cout << "4. Find Customer by ID\n";
    std::cout << "5. Delete Customer\n";
    std::cout << "6. View Total Customers\n";
    std::cout << "7. Go Back to Dashboard\n";
    std::cout << "Enter your choice: ";

}


void addRegularCustomer(CustomerManager& manager) {
    int id;
    std::string name, mobileNumber;

    std::cout << "Enter Customer ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Mobile Number: ";
    std::getline(std::cin, mobileNumber);

    manager.addRegularCustomer(id, name, mobileNumber);
    std::cout << "Regular customer added successfully!\n";
}



void addPremiumCustomer(CustomerManager& manager) {
    int id;
    std::string name, membershipId;

    std::cout << "Enter Customer ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Membership ID: ";
    std::getline(std::cin, membershipId);

    manager.addPremiumCustomer(id, name, membershipId);
    std::cout << "Premium customer added successfully!\n";
}


void findCustomerById(CustomerManager& manager) {
    int id;

    std::cout << "Enter Customer ID to search: ";
    std::cin >> id;

    try {
        const BaseCustomer* customer = manager.findCustomerById(id);
        std::cout << "Customer found:\n";
        customer->display();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void viewAllCustomers(CustomerManager& manager) {
    manager.viewCustomers();
    
}

void deleteCustomer(CustomerManager& manager) {
    int id;

    std::cout << "Enter Customer ID to delete: ";
    std::cin >> id;

    manager.deleteCustomer(id);
}
void viewTotolCustomers(CustomerManager& manager) {
    manager.getTotalCustomers();
}




void customerManage(CustomerManager& customerManager) {

    int customerChoise;
    bool customerManage = true;
    //Adding sample customers

    while (customerManage) {
        dispalyCustomerMenu();
        std::cin >> customerChoise;

        switch (customerChoise) {
        case 1:
            system("CLS");
            addRegularCustomer(customerManager);
            break;
        case 2:
            system("CLS");
            addPremiumCustomer(customerManager);
            break;
        case 3:
            system("CLS");
            viewAllCustomers(customerManager);
            break;
        case 4:
            system("CLS");
            findCustomerById(customerManager);
            break;
        case 5:
            system("CLS");
            deleteCustomer(customerManager);
            break;
        case 6:
            system("CLS");
            viewTotolCustomers(customerManager);
            break;
        case 7:
            system("CLS");
            customerManage = false;
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }

}



void dispalySupplierMenu() {
    std::cout << "===================================" << std::endl;
    std::cout << "          Supplier Manage         " << std::endl;
    std::cout << "===================================" << std::endl;
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
    std::cout << "===================================" << std::endl;
    std::cout << "          Place Order Manage      " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "1. place order" << std::endl;
    std::cout << "2. Go Back to Dashboard" << std::endl;
    std::cout << "Enter your choice: ";
}



void setPlaceOrder(Place_order& place_order, CustomerManager& customerManager, Item_manager& itemManager) {
    place_order.placeOrder(customerManager, itemManager);

}



void place_order(Place_order& placeOrder, CustomerManager& customerManager, Item_manager& itemManager) {

    int placeOrderChoise;
    bool placeOrderMange = true;


    while (placeOrderMange) {
        dispalyPlaceOrder();
        std::cin >> placeOrderChoise;

        switch (placeOrderChoise){
        case   1:
            system("CLS");
            setPlaceOrder(placeOrder, customerManager, itemManager);
            break;
        case 2:
            system("CLS");
            placeOrderMange = false;
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
           
        }

    }


}


void connectToServer() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
        return;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed." << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8081);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Connection to server failed." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return;
    }

    const char* message = "Hello from Client!";
    send(clientSocket, message, strlen(message), 0);

    char response[512];
    int bytesReceived = recv(clientSocket, response, sizeof(response), 0);
    if (bytesReceived > 0) {
        response[bytesReceived] = '\0';
        std::cout << "Server: " << response << std::endl;
    }

    closesocket(clientSocket);
    WSACleanup();
}



int main()
{
    Item_manager itemManager;
    customer_manager customerManager;
    Supplier_manager supplierManager;
    Place_order placeOrder;
   


    CustomerManager manager;
   

    int itemChoice;
    bool running  = true;

    connectToServer();
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
            customerManage(manager);
            break;
        case 3:
            system("CLS");
            supplierManagers(supplierManager);
            break;
        case 4:
            system("CLS");

           /* supplierManager.addSupplier(1, "lamal", "0769773032", "a@gmail.com", "qwer");
            itemManager.addItem(1, "apple", 12, 120, 1);
            itemManager.addItem(2, "orange", 12, 120, 1);
            customerManager.addCustomer(1, "Tharindu", "0786667878");*/

            place_order(placeOrder, manager, itemManager);
            break;
        case 5:
            system("CLS");
            std::cout << "Exiting... Thank you!" << std::endl;
            running = false;
        default:
            std::cout << "Invalid choice! Please try again.\n" << std::endl;
        }
    }
    return 0;



}

