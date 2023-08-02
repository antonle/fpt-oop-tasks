#pragma once

#include <string>
#include <memory>

#include "Room.h"

class Customer {
public:
	using sptrRoom = std::shared_ptr<Room>;

	Customer(const std::string& name, int age, const std::string& passport_number, int days, const sptrRoom& room);
	~Customer();
	Customer(const Customer& other);
	Customer& operator=(const Customer& other);

	int getDays() const;
	sptrRoom getRoom() const;

private:
	std::string name_;
	int age_;
	std::string passport_number_;
	int days_;
	sptrRoom room_;
};
