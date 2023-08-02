#include "Customer.h"

Customer::Customer(const std::string& name, int age, const std::string& passport_number, int days, const sptrRoom& room): name_(name),
																												age_(age),
																												passport_number_(passport_number),
																												days_(days),
																												room_(sptrRoom(room))
{}

Customer::~Customer() {}

Customer::Customer(const Customer& other): Customer(other.name_, other.age_, other.passport_number_, other.days_, other.room_) {}

Customer& Customer::operator=(const Customer& other) {
	name_ = other.name_;
	age_ = other.age_;
	passport_number_ = other.passport_number_;
	room_ = other.room_;
	days_ = other.days_;

	return *this;
}

int Customer::getDays() const {
	return days_;
}

Customer::sptrRoom Customer::getRoom() const {
	return room_;
}
