#include <iostream>

#include "Staff.h"

Staff::Staff(const std::string& name, int age, Sex sex, const std::string& address, const std::string& job): Employee(name, age, sex, address, Indicator::STAFF),
																												   job_(job)
{}

Staff::~Staff() {}

Staff::Staff(const Staff& other): Staff(other.name_, other.age_, other.sex_, other.address_, other.job_) {}

Staff& Staff::operator=(const Staff& other) {
	name_ = other.name_;
	age_ = other.age_;
	sex_ = other.sex_;
	address_ = other.address_;
	job_ = other.job_;

	return *this;
}

void Staff::printDetailedInfo() const {
	printGeneralInfo();
	std::cout << "job: " << job_ << '\n';
	std::cout << '\n';
}
