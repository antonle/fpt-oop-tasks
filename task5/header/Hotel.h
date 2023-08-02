#pragma once

#include <unordered_map>
#include <memory>
#include <iostream>

#include "Room.h"
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include "Customer.h"

class Hotel {
public:
	Hotel();
	~Hotel();

	void run();

private:
	void printMenu();
	void addNewCustomer();
	void deleteCustomer();
	void calculateCost();
	void exit();

	std::unordered_map<std::string, std::shared_ptr<Customer>> customers_;
	bool is_done_;
};
