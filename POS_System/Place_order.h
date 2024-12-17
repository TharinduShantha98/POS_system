#pragma once
#include "Order.h"
#include "customer_manager.h"
#include "Item_manager.h"
#include <iostream>



class Place_order
{
public:
	void placeOrder(customer_manager& customerManager, Item_manager& itemManager);
};

