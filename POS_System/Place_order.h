#pragma once
#include "Order.h"
#include "customer_manager.h"
#include "CustomerManager.h"
#include "Item_manager.h"
#include <iostream>



class Place_order
{
public:
	void placeOrder(CustomerManager& customerManager, Item_manager& itemManager);
};

